#include "x86DException.h"
#include "x86Instruction.h"
#include "x86ModRM.h"
#include "x86SIB.h"


// --------------------------------------------------------------------------------------
// Function:  FillInstruction
// Parameters: None
// Special Notes: None
// --------------------------------------------------------------------------------------
bool x86ModRM::FillInstruction(const x86OpcodeMap* opcode, x86Instruction* instruction)
{
  // First count the number of operands
  size_t operandCount = 0;
  for (size_t i = 0; i < MAX_OPERANDS; ++i)
  {
    if (REG::NO_REG == opcode->Operands[i])
    {
      break;
    }

    ++operandCount;
  }

  // ModRM specified means there must be at least one operand.
  if (0 == operandCount)
  {
    return false;
  }

  return GetModRMOperands(instruction, opcode->Operands, operandCount);
}

// --------------------------------------------------------------------------------------
// Function:  FillExtendedInstruction
// Parameters: None
// Special Notes: Retrieves the operand using Mod + RM
// --------------------------------------------------------------------------------------
bool x86ModRM::FillExtendedInstruction(const x86OpcodeMap* opcode,
                                       x86Instruction* instruction)
{
  bool success = true;
  uint32_t extension = RegOpcode;

  const x86OpcodeMap::ExtensionTable* eOpcode = nullptr;
  switch (opcode->_Mnemonic)
  {
  case Mnemonic::EXT80:
  case Mnemonic::EXT81:
  case Mnemonic::EXT83:
  case Mnemonic::EXTC0:
  case Mnemonic::EXTC1:
  case Mnemonic::EXTD0:
  case Mnemonic::EXTD1:
  case Mnemonic::EXTD2:
  case Mnemonic::EXTD3:
  case Mnemonic::EXT_4:
  case Mnemonic::EXT_5:
  case Mnemonic::EXT_6:
  case Mnemonic::EXT_7:
  case Mnemonic::EXT_8:
  case Mnemonic::EXT_9:
  case Mnemonic::EXT_A:
  case Mnemonic::EXT_B:
  case Mnemonic::EXT_C:
  case Mnemonic::EXT_D:
  case Mnemonic::EXT_E:
  case Mnemonic::EXT_F:
  case Mnemonic::OPF_0:
  case Mnemonic::OPF_1:
  case Mnemonic::OPF_2:
  case Mnemonic::OPF_3:
  case Mnemonic::OPF_4:
  case Mnemonic::OPF_5:
  case Mnemonic::OPF_6:
    eOpcode = x86OpcodeMap::ExtensionTables[opcode->_Mnemonic - Mnemonic::EXT80];
    break;
  default:
    success = false;
  }

  if (nullptr != eOpcode)
  {
    while (Mnemonic::MAX_OPCODE != eOpcode->mnemonic)
    {
      // Find the matching extension which is found in the RegOpcode field.
      if (eOpcode->extension == RegOpcode)
      {
        // Find the secondary opcode if specified.
        if (0 == eOpcode->secondaryOpcode)
        {
          break; // No secondary opcode, we found it.
        }
        else if (ModRM == eOpcode->secondaryOpcode)
        {
          break; // Secondary opcode found.
        }
      }
      ++eOpcode;
    }

    // Check for an invalid extended opcode..
    if (Mnemonic::MAX_OPCODE == eOpcode->mnemonic)
    {
      // For some reason, there are extensions being used that are not defined.
      // For this reason, set mnemonic to DB and return true to continue
      // disassembling.
      throw x86DException(x86DException::INVALID_OPCODE_MAP,
                          instruction->GetRelativeAddress(),
                          false);

      return true;
    }

    // Update the mnemonic
    instruction->SetMnemonic(eOpcode->mnemonic);
    instruction->AddDescription(MnemonicStrings[eOpcode->mnemonic]);

    // Count the number of operands
    size_t operandCount = 0;
    for (size_t i = 0; i < MAX_OPERANDS; ++i)
    {
      if (REG::NO_REG == eOpcode->Operands[i])
      {
        break;
      }

      ++operandCount;
    }

    return GetModRMOperands(instruction, eOpcode->Operands, operandCount, true);
  }

  return success;
}

// --------------------------------------------------------------------------------------
// Function:  AppendSegmentOverride
// Parameters: 
//   (I) operand - Operand string
// Special Notes: None
// --------------------------------------------------------------------------------------
void x86ModRM::AppendSegmentOverride(std::string& operand) const
{
  // ModRM Registers may contain segment overrides..
  switch (Prefix)
  {
  case OpcodePrefix::ES_OVERRIDE:
    operand = "ES:" + operand;
    break;
  case OpcodePrefix::CS_OVERRIDE:
    operand = "CS:" + operand;
    break;
  case OpcodePrefix::SS_OVERRIDE:
    operand = "SS:" + operand;
    break;
  case OpcodePrefix::DS_OVERRIDE:
    operand = "DS:" + operand;
    break;
  case OpcodePrefix::FS_OVERRIDE:
    operand = "FS:" + operand;
    break;
  case OpcodePrefix::GS_OVERRIDE:
    operand = "GS:" + operand;
    break;
  default: break;
  }
}

// --------------------------------------------------------------------------------------
// Function:  GetModRMOperands
// Parameters: None
// Special Notes: Retrieves the operand using Mod + RM
// --------------------------------------------------------------------------------------
bool x86ModRM::GetModRMOperands(x86Instruction* instruction,
                                const REG* operands,
                                size_t numOperands,
                                bool ignoreOverride) const
{
  bool success = true;

  for (size_t i = 0; i < numOperands; ++i)
  {
    // Do not continue if a failure was detected.
    if (false == success)
    {
      break;
    }

    // First let's map the OpcodeMap operand to a potential ModRM operand
    REG reg = operands[i];
    switch (reg)
    {
      // Register opcodes and M8 take the data from the ModRegRTable
      case REG::R8:
      {
        reg = static_cast<REG>(ModRegRegisterTable[RegOpcode][REG8]);
      }
      break;

      case REG::R16:
      {
        reg = static_cast<REG>(ModRegRegisterTable[RegOpcode][REG16]);
      }
      break;

      case REG::R16_32:
      {
        if (OpcodePrefix::OPERAND_SIZE == Prefix)
        {
          reg = static_cast<REG>(ModRegRegisterTable[RegOpcode][REG16]);
        }
        else
        {
          reg = static_cast<REG>(ModRegRegisterTable[RegOpcode][REG32]);
        }
      }
      break;

      case REG::R32:
      {
        reg = static_cast<REG>(ModRegRegisterTable[RegOpcode][REG32]);
      }
      break;

      // 128/256-Bit Registers
      case REG::MMX:
      {
        reg = static_cast<REG>(ModRegRegisterTable[RegOpcode][REGMM]);
      }
      break;

      case REG::XMM:
      {
        reg = static_cast<REG>(ModRegRegisterTable[RegOpcode][REGXMM]);
      }
      break;

      case REG::CR:
      {
        reg = static_cast<REG>(ModRegRegisterTable[RegOpcode][REGCR]);
      }
      break;

      case REG::DR:
      {
        reg = static_cast<REG>(ModRegRegisterTable[RegOpcode][REGDR]);
      }
      break;

      // The following register types (M*) may require additional 
      // processing. They will pull from either ModRMReg16/32Table
      case REG::M8:
      {
        reg = static_cast<REG>(ModReg8Table[RM][Mod]);
      }
      break;

      case REG::M16:
      {
        reg = static_cast<REG>(ModReg16Table[RM][Mod]);
      }
      break;

      case REG::M16_32:
      {
        if (OpcodePrefix::OPERAND_SIZE == Prefix)
        {
          reg = static_cast<REG>(ModReg16Table[RM][Mod]);
        }
        else
        {
          reg = static_cast<REG>(ModReg32Table[RM][Mod]);
        }
      }
      break;

      case REG::M32:
      {
        reg = static_cast<REG>(ModReg32Table[RM][Mod]);
      }
      break;

      case REG::M32_256:
      {
        if (OpcodePrefix::OPERAND_SIZE == Prefix)
        {
          reg = static_cast<REG>(ModReg32Table[RM][Mod]);
        }
        else
        {
          reg = static_cast<REG>(static_cast<uint32_t>(REG::XMM0) + RegOpcode);
        }
      }
      break;

      case REG::M64_128:
      {
        if (OpcodePrefix::OPERAND_SIZE == Prefix)
        {
          reg = static_cast<REG>(static_cast<uint32_t>(REG::XMM0) + RegOpcode);
        }
        else
        {
          reg = static_cast<REG>(static_cast<uint32_t>(REG::YMM0) + RegOpcode);
        }
      }
      break;

      case REG::M64_256:
      {
        if (OpcodePrefix::OPERAND_SIZE == Prefix)
        {
          reg = static_cast<REG>(static_cast<uint32_t>(REG::MMX0) + RegOpcode);
        }
        else
        {
          reg = static_cast<REG>(static_cast<uint32_t>(REG::YMM0) + RegOpcode);
        }
      }
      break;

      case REG::M128_256:
      {
        if (OpcodePrefix::OPERAND_SIZE == Prefix)
        {
          reg = static_cast<REG>(static_cast<uint32_t>(REG::YMM0) + RegOpcode);
        }
        else
        {
          reg = static_cast<REG>(static_cast<uint32_t>(REG::XMM0) + RegOpcode);
        }
      }
      break;

      case REG::STi:
      {
        reg = static_cast<REG>(static_cast<uint32_t>(REG::ST0) + RM);
      }
      break;

      // Segment Register
      case REG::SREG:
      {
        reg = static_cast<REG>(ModRegRegisterTable[RegOpcode][SEGMENT]);
      }
      break;

      // The following register types (STi/M32_REAL) requires additional
      // processing..
      case REG::M16_INT:
      case REG::M32_FP:
      case REG::M64_FP:
      case REG::M80_DEC:
      {
        return GetFPOperands(instruction, reg); // return from this call
      }
      break;

      default: break; // No Exception here due to explicit registers
    }

    // Do not continue if a failure was detected (FP Registers)
    if (false == success)
    {
      break;
    }

    std::string operandStr;
    success = TranslateRegister(instruction, reg, operandStr, ignoreOverride);
    if ((true == success) &&
        (0 != operandStr.length())) // M*_FP will return with no string.
    {
      instruction->AddDescription(operandStr);
    }
  }

  return success;
}

// --------------------------------------------------------------------------------------
// Function:  GetFPOperands
// Parameters: 
//   (I) instruction - the instruction to modify
// Special Notes: None
// --------------------------------------------------------------------------------------
bool x86ModRM::GetFPOperands(x86Instruction* instruction, REG operand) const
{
  bool success = true;

  // Calculate the STi Offset using the opcode byte of data and the Mnemonic..
  uint8_t stOffset = 0xFF;
  uint8_t firstByte = instruction->GetData()[OpcodePrefix::NO_PREFIX == Prefix ? 0 : 1];
  switch (firstByte)
  {
    case 0xD8:
    {
      switch (instruction->GetMnemonic())
      {
        case Mnemonic::FADD:
          stOffset = 0xC0; 
          break;
        case Mnemonic::FMUL:
          stOffset = 0xC8;
          break;
        case Mnemonic::FCOM:
          stOffset = 0xD0;
          break;
        case Mnemonic::FCOMP:
          stOffset = 0xD8;
          break;
        case Mnemonic::FSUB:
          stOffset = 0xE0;
          break;
        case Mnemonic::FSUBR:
          stOffset = 0xE8;
          break;
        case Mnemonic::FDIV:
          stOffset = 0xF0;
          break;
        case Mnemonic::FDIVR:
          stOffset = 0xF8;
          break;
        default: break;
      }
    }
    break;  

    case 0xD9:
    {
      switch (instruction->GetMnemonic())
      {
        case Mnemonic::FLD:
          stOffset = 0xC0;
          break;
        default: break;
      }
    }
    break;

    case 0xDA:
    {
      switch (instruction->GetMnemonic())
      {
        case Mnemonic::FCMOVB:
          stOffset = 0xC0;
          break;
        case Mnemonic::FCMOVE:
          stOffset = 0xC8;
          break;
        case Mnemonic::FCMOVBE:
          stOffset = 0xD0;
          break;
        case Mnemonic::FCMOVU:
          stOffset = 0xD8;
          break;
        default: break;
      }
    }
    break;

    case 0xDB:
    {
      switch (instruction->GetMnemonic())
      {
        case Mnemonic::FCMOVNB:
          stOffset = 0xC0;
          break;
        case Mnemonic::FCMOVNE:
          stOffset = 0xC8;
          break;
        case Mnemonic::FCMOVBE:
          stOffset = 0xD0;
          break;
        case Mnemonic::FCMOVNU:
          stOffset = 0xD8;
          break;
        case Mnemonic::FUCOMI:
          stOffset = 0xE8;
          break;
        case Mnemonic::FCOMI:
          stOffset = 0xF0;
          break;
        default: break;
      }
    }
    break;

    case 0xDC:
    {
      switch (instruction->GetMnemonic())
      {
        case Mnemonic::FADD:
          stOffset = 0xC0;
          break;
        case Mnemonic::FMUL:
          stOffset = 0xC8;
          break;
        case Mnemonic::FSUBR:
          stOffset = 0xE0;
          break;
        case Mnemonic::FSUB:
          stOffset = 0xE8;
          break;
        case Mnemonic::FDIVR:
          stOffset = 0xF0;
          break;
        case Mnemonic::FDIV:
          stOffset = 0xF8;
          break;
        default: break;
      }
    }
    break;

    case 0xDD:
    {
      switch (instruction->GetMnemonic())
      {
        case Mnemonic::FFREE:
          stOffset = 0xC0;
          break;
        case Mnemonic::FXCH4:
          stOffset = 0xC8;
          break;
        case Mnemonic::FST:
          stOffset = 0xD0;
          break;
        case Mnemonic::FSTP:
          stOffset = 0xD8;
          break;
        case Mnemonic::FUCOM:
          stOffset = 0xE0;
          break;
        case Mnemonic::FUCOMP:
          stOffset = 0xE8;
          break;
        default: break;
      }
    }
    break;

    case 0xDE:
    {
      switch (instruction->GetMnemonic())
      {
        case Mnemonic::FADDP:
          stOffset = 0xC0;
          break;
        case Mnemonic::FMULP:
          stOffset = 0xC8;
          break;
        case Mnemonic::FCOMP5:
          stOffset = 0xD0;
          break;
        case Mnemonic::FCOMPP:
          stOffset = 0xD8;
          break;
        case Mnemonic::FSUBRP:
          stOffset = 0xE0;
          break;
        case Mnemonic::FSUBP:
          stOffset = 0xE8;
          break;
        case Mnemonic::FDIVRP:
          stOffset = 0xF0;
          break;
        case Mnemonic::FDIVP:
          stOffset = 0xF8;
          break;
      }
    }
    break;

    case 0xDF:
    {
      switch (instruction->GetMnemonic())
      {
        case Mnemonic::FFREEP:
          stOffset = 0xC0;
          break;
        case Mnemonic::FXCH7:
          stOffset = 0xC8;
          break;
        case Mnemonic::FSTP8:
          stOffset = 0xD0;
          break;
        case Mnemonic::FSTP9:
          stOffset = 0xD8;
          break;
        case Mnemonic::FBLD:
          stOffset = 0xE0;
          break;
        case Mnemonic::FUCOMIP:
          stOffset = 0xE8;
          break;
        case Mnemonic::FCOMIP:
          stOffset = 0xF0;
          break;
        case Mnemonic::FISTP:
          stOffset = 0xF8;
          break;
      }
    }
    break;

    default:
      success = false;
  }

  if (true == success)
  {
    if (stOffset > ModRM) // M16_INT
    {
      std::string operandStr;
        
      switch (operand)
      {
        case M16_INT:
        {
          success = TranslateRegister(instruction, 
                                      static_cast<REG>(ModReg16Table[RM][Mod]), 
                                      operandStr,
                                      true); // Ignore override so we can add it here
        }
        break;

        case M32_FP:
        case M64_FP:
        case M80_DEC:
        {
          success = TranslateRegister(instruction,
                                      static_cast<REG>(ModReg32Table[RM][Mod]),
                                      operandStr,
                                      true); // Ignore override so we can add it here
        }
        break;

        default:
          success = false;
      }

      if (true == success)
      {
        char fOperandStr[32] = { 0 };

        AppendSegmentOverride(operandStr);
        sprintf_s(fOperandStr, "%s %s", REGStrings[M16_INT], operandStr.c_str());
        instruction->AddDescription(fOperandStr);
      }
    }
    else // STi
    {
      char operandStr[32] = { 0 };
      sprintf_s(operandStr, "%s(%d)", REGStrings[static_cast<uint32_t>(ST0) + RM], RM);
      instruction->AddDescription(operandStr);
    }
  }

  return success;
}

// --------------------------------------------------------------------------------------
// Function:  TranslateRegister
// Parameters: 
//   (I) instruction - the instruction to modify
// Special Notes: None
// --------------------------------------------------------------------------------------
bool x86ModRM::TranslateRegister(x86Instruction* instruction, 
                                 REG operand, 
                                 std::string& operandStr,
                                bool ignoreOverride) const
{
  bool success = true;

  // The REG should've been updated for Regs/ModRM. This next switch statement
  // will complete the rest of the translation.
  switch (operand)
  {
    // ----------------------------------------
    // Process all explicit registers
    case AL:
    case CL:
    case DL:
    case BL:
    case AH:
    case CH:
    case DH:
    case BH:
    case AX:
    case CX:
    case DX:
    case BX:
    case SP:
    case BP:
    case SI:
    case DI:
    case EAX:
    case ECX:
    case EDX:
    case EBX:
    case ESP:
    case EBP:
    case ESI:
    case EDI:
    case RAX:
    case RCX:
    case RDX:
    case RBX:
    case RSP:
    case RBP:
    case RSI:
    case RDI:
    case ST1:
    case ST2:
    case ST3:
    case ST4:
    case ST5:
    case ST6:
    case ST7:
    case MMX0:
    case MMX1:
    case MMX2:
    case MMX3:
    case MMX4:
    case MMX5:
    case MMX6:
    case MMX7:
    case XMM0:
    case XMM1:
    case XMM2:
    case XMM3:
    case XMM4:
    case XMM5:
    case XMM6:
    case XMM7:
    case XMM8:
    case XMM9:
    case XMM10:
    case XMM11:
    case XMM12:
    case XMM13:
    case XMM14:
    case XMM15:
    case YMM0:
    case YMM1:
    case YMM2:
    case YMM3:
    case YMM4:
    case YMM5:
    case YMM6:
    case YMM7:
    case YMM8:
    case YMM9:
    case YMM10:
    case YMM11:
    case YMM12:
    case YMM13:
    case YMM14:
    case YMM15:
    case DS:
    case ES:
    case FS:
    case GS:
    case SS:
    case CS:
    case IP:
    case CR0:
    case CR1:
    case CR2:
    case CR3:
    case CR4:
    case CR5:
    case CR6:
    case CR7:
    case CR8:
    case CR9:
    case CR10:
    case CR11:
    case CR12:
    case CR13:
    case CR14:
    case CR15:
    case DR0:
    case DR1:
    case DR2:
    case DR3:
    case DR4:
    case DR5:
    case DR6:
    case DR7:
    case DR8:
    case DR9:
    case DR10:
    case DR11:
    case DR12:
    case DR13:
    case DR14:
    case DR15:
    case BX_SI:
    case BX_DI:
    case BP_SI:
    case BP_DI:
    case _EAX:
    case _ECX:
    case _EDX:
    case _EBX:
    case _ESI:
    case _EDI:
    {
      operandStr = REGStrings[operand];
    }
    break;
    // ----------------------------------------

    // ----------------------------------------
    // Handle all Immediate types..
    case REG::I8:
    {
      uint8_t imm8 = instruction->GetNext8();
      instruction->AddData(reinterpret_cast<char*>(&imm8), 1);

      char str[3] = { 0 };
      sprintf_s(str, "%02X", imm8);
      operandStr = str;
    }
    break;

    case REG::I16_32:
    {
      if (OpcodePrefix::OPERAND_SIZE == Prefix)
      {
        uint16_t imm16 = instruction->GetNext16();
        instruction->AddData(reinterpret_cast<char*>(&imm16), 2);

        char str[5] = { 0 };
        sprintf_s(str, "%04X", imm16);
        operandStr = str;
      }
      else
      {
        uint32_t imm32 = instruction->GetNext32();
        instruction->AddData(reinterpret_cast<char*>(&imm32), 4);

        char str[9] = { 0 };
        sprintf_s(str, "%08X", imm32);
        operandStr = str;
      }
    }
    break;

    case REG::_I16:
    {
      uint16_t imm16 = instruction->GetNext16();
      instruction->AddData(reinterpret_cast<char*>(&imm16), 2);

      char str[7] = { 0 };
      sprintf_s(str, "[%04X]", imm16);
      operandStr = str;
    }
    break;

    case REG::_U32:
    {
      uint32_t imm32 = instruction->GetNext32();
      instruction->AddData(reinterpret_cast<char*>(&imm32), 4);

      char str[11] = { 0 };
      sprintf_s(str, "[%08X]", imm32);
      operandStr = str;
    }
    break;
    // ----------------------------------------

    // ----------------------------------------
    // Handle all Register + Immediate types...
    case BX_SI_D8:
    case BX_DI_D8:
    case BP_SI_D8:
    case BP_DI_D8:
    case SI_D8:
    case DI_D8:
    case BP_D8:
    case BX_D8:
    case EAX_D8:
    case ECX_D8:
    case EDX_D8:
    case EBX_D8:
    case EBP_D8:
    case ESI_D8:
    case EDI_D8:
    {
      int8_t imm8 = instruction->GetNext8();
      instruction->AddData(reinterpret_cast<char*>(&imm8), 1);

      char str[32] = { 0 };
      sprintf_s(str,
                "[%s%s%02X]",
                REGStrings[operand],
                imm8 < 0 ? "-" : "+",
                abs(imm8));
      operandStr = str;
    }
    break;

    case BX_SI_D16:
    case BX_DI_D16:
    case BP_SI_D16:
    case BP_DI_D16:
    case SI_D16:
    case BP_D16:
    case BX_D16:
    {
      int16_t imm16 = instruction->GetNext16();
      instruction->AddData(reinterpret_cast<char*>(&imm16), 2);

      char str[32] = { 0 };
      sprintf_s(str,
                "[%s%s%04X]",
                REGStrings[operand],
                imm16 < 0 ? "-" : "+",
                abs(imm16));
      operandStr = str;
    }
    break;

    case EAX_D32:
    case ECX_D32:
    case EDX_D32:
    case EBX_D32:
    case EBP_D32:
    case ESI_D32:
    case EDI_D32:
    {
      int32_t imm32 = instruction->GetNext32();
      instruction->AddData(reinterpret_cast<char*>(&imm32), 4);

      char str[32] = { 0 };
      sprintf_s(str,
                "[%s%s%08X]",
                REGStrings[operand],
                imm32 < 0 ? "-" : "+",
                abs(imm32));
      operandStr = str;
    }
    break;

    // ----------------------------------------
    // Handle SIB
    case SIB:
    {

    }
    break;

    case _SIB:
    {
      // Pass control off to x86SIB
      uint8_t sibByte = instruction->GetNext8();
      instruction->AddData(reinterpret_cast<char*>(&sibByte), 1);

      x86SIB sib(sibByte, Mod, Prefix);
      success = sib.GetOperand(instruction, operandStr);
    }
    break;

    // Retrieve MOffset 16/32
    case REG::MO_16_32:
    case REG::MO_8:
    {
      uint32_t imm32 = instruction->GetNext32();
      instruction->AddData(reinterpret_cast<char*>(&imm32), 4);

      char str[12] = { 0 };
      sprintf_s(str, "[%08X]", imm32);

      std::string operand = str;
      x86ModRM modRM(0, Prefix);
      modRM.AppendSegmentOverride(operand);

      instruction->AddDescription(operand);
    }
    break;

    // These operands should have been processed by GetFPOperands
    case STi:
    case M32_FP:
    case M64_FP:
      break;

      // Unable to map Operand...
    default:
      throw x86DException(x86DException::INVALID_REG_MAP,
                          instruction->GetRelativeAddress(),
                          true);
  }

  if ((true == success) &&
      (false == ignoreOverride))
  {
    AppendSegmentOverride(operandStr);
  }

  return success;
}

// --------------------------------------------------------------------------------------
// Function:  x86ModRM
// Parameters: None
// Special Notes: None
// --------------------------------------------------------------------------------------
x86ModRM::x86ModRM(uint8_t modRM, OpcodePrefix prefix) :
  ModRM(modRM),
  Mod(0),
  RegOpcode(0),
  RM(0),
  Prefix(prefix)
{
  Mod = modRM >> 6;                // **00 0000
  RegOpcode = (modRM & 0x38) >> 3; // 00** *000
  RM = modRM & 0x7;                // 0000 0***
}

// --------------------------------------------------------------------------------------
// Function:  ~x86ModRM
// Parameters: None
// Special Notes: None
// --------------------------------------------------------------------------------------
x86ModRM::~x86ModRM()
{

}