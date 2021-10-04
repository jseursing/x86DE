#include "x86DException.h"
#include "x86Instruction.h"
#include "x86ModRM.h"
#include "x86OpcodeMap.h"


// --------------------------------------------------------------------------------------
// Function:  GetNext8
// Parameters: None.
// Special Notes: Gets the next byte and increments CurrentOffset.
// --------------------------------------------------------------------------------------
int8_t x86Instruction::GetNext8()
{
  if (CurrentOffset >= MaximumLength)
  {
    throw x86DException(x86DException::BUFFER_OVERFLOW,
                        RelativeAddress + CurrentOffset - Data.size(),
                        true);
  }

  return Buffer[CurrentOffset++];
}

// --------------------------------------------------------------------------------------
// Function:  GetNext16
// Parameters: None.
// Special Notes: Gets the next short and increments CurrentOffset.
// --------------------------------------------------------------------------------------
int16_t x86Instruction::GetNext16()
{
  if (CurrentOffset >= (MaximumLength - 2))
  {
    throw x86DException(x86DException::BUFFER_OVERFLOW,
                        RelativeAddress + CurrentOffset - Data.size(),
                        true);
  }

  uint16_t val = *reinterpret_cast<uint16_t*>(&Buffer[CurrentOffset]);
  CurrentOffset += 2;
  
  return val;
}

// --------------------------------------------------------------------------------------
// Function:  GetNext32
// Parameters: None.
// Special Notes: Gets the next int and increments CurrentOffset.
// --------------------------------------------------------------------------------------
int32_t x86Instruction::GetNext32()
{
  if (CurrentOffset >= (MaximumLength - 4))
  {
    throw x86DException(x86DException::BUFFER_OVERFLOW,
                        RelativeAddress + CurrentOffset - Data.size(),
                        true);
  }

  uint32_t val = *reinterpret_cast<uint32_t*>(&Buffer[CurrentOffset]);
  CurrentOffset += 4;

  return val;
}

// --------------------------------------------------------------------------------------
// Function:  PeekNext8
// Parameters: None.
// Special Notes: Gets the next byte without incrementing CurrentOffset.
// --------------------------------------------------------------------------------------
int8_t x86Instruction::PeekNext8() const
{
  if (CurrentOffset >= MaximumLength)
  {
    throw x86DException(x86DException::BUFFER_OVERFLOW,
                        RelativeAddress + CurrentOffset - Data.size(),
                        true);
  }

  return Buffer[CurrentOffset];
}

// --------------------------------------------------------------------------------------
// Function:  SetMnemonic
// Parameters:
//   (I) mnem - The Mnemonic
// Special Notes: None
// --------------------------------------------------------------------------------------
void x86Instruction::SetMnemonic(Mnemonic mnem)
{
  _Mnemonic = mnem;
}

// --------------------------------------------------------------------------------------
// Function:  GetMnemonic
// Parameters: None
// Special Notes: None
// --------------------------------------------------------------------------------------
Mnemonic x86Instruction::GetMnemonic() const
{
  return _Mnemonic;
}

// --------------------------------------------------------------------------------------
// Function:  SetOperand
// Parameters:
//   (I) operand - The operand
//   (I) operandIdx - The operand's index
// Special Notes: None
// --------------------------------------------------------------------------------------
void x86Instruction::SetOperand(REG operand, size_t operandIdx)
{
  if (operandIdx < MAX_OPERANDS)
  {
    Operands[operandIdx] = operand;
  }
}

// --------------------------------------------------------------------------------------
// Function:  GetOperand
// Parameters: None
// Special Notes: None
// --------------------------------------------------------------------------------------
REG x86Instruction::GetOperand(size_t operandIdx) const
{
  if (operandIdx < MAX_OPERANDS)
  {
    return Operands[operandIdx];
  }

  return REG::NO_REG;
}

// --------------------------------------------------------------------------------------
// Function:  AddData
// Parameters: None.
// Special Notes: None
// --------------------------------------------------------------------------------------
void x86Instruction::AddData(char* data, size_t len)
{
  for (size_t i = 0; i < len; ++i)
  {
    Data.push_back(static_cast<uint8_t>(data[i]));
  }
}

// --------------------------------------------------------------------------------------
// Function:  GetData
// Parameters: None.
// Special Notes: None
// --------------------------------------------------------------------------------------
std::vector<uint8_t>& x86Instruction::GetData()
{
  return Data;
}

// --------------------------------------------------------------------------------------
// Function:  GetDescription
// Parameters: None.
// Special Notes: None
// --------------------------------------------------------------------------------------
std::vector<std::string>& x86Instruction::GetDescription()
{
  return Description;
}

// --------------------------------------------------------------------------------------
// Function:  AddDescription
// Parameters: None.
// Special Notes: None
// --------------------------------------------------------------------------------------
void x86Instruction::AddDescription(std::string desc)
{
  Description.push_back(desc);
}

// --------------------------------------------------------------------------------------
// Function:  GetRelativeAddress
// Parameters: None.
// Special Notes: None
// --------------------------------------------------------------------------------------
uintptr_t x86Instruction::GetRelativeAddress() const
{
  return RelativeAddress + CurrentOffset - Data.size();
}

// --------------------------------------------------------------------------------------
// Function:  BuildInstruction
// Parameters: None.
// Special Notes: None
// --------------------------------------------------------------------------------------
std::string x86Instruction::BuildInstruction() const
{
  std::string x86Instruction;
  if (0 != Description.size())
  {
    x86Instruction = Description[0];

    for (size_t i = 1; i < Description.size(); ++i)
    {
      x86Instruction += (1 == i ? " " : ", ") + Description[i];
    }
  }

  return x86Instruction;
}

// --------------------------------------------------------------------------------------
// Function:  x86Instruction
// Parameters:
//   (I) buffer - Pointer to data
//   (I) offset - Length of data
//   (I) maxLength - Maximum length of buffer
//   (I) relativeAddr - The base address of data the buffer contains
// Special Notes: None
// --------------------------------------------------------------------------------------
x86Instruction::x86Instruction(char* buffer, 
                               size_t& offset, 
                               size_t maxLength, 
                               uint32_t relativeAddr,
                               bool& success) :
  Buffer(buffer),
  CurrentOffset(offset),
  MaximumLength(maxLength),
  RelativeAddress(relativeAddr),
  Prefix(OpcodePrefix::NO_PREFIX),
  _Mnemonic(Mnemonic::DB),
  Operands{ REG::NO_REG, REG::NO_REG , REG::NO_REG , REG::NO_REG }
{
  // Store the original offset.
  size_t originalOffset = offset;  

  // Do not continue with 0 MaxLength.. 
  if (0 == maxLength)
  {
    success = false;
    return;
  }

  // Start off by retrieving the first byte.
  uint8_t firstByte = GetNext8();
  Data.push_back(firstByte);

  // Begin the Finite-State-Machine
  success = PopulateInstruction(firstByte);
  
  // If a failure was detected reset the offset.
  offset = (false == success ? originalOffset : CurrentOffset);
}

// --------------------------------------------------------------------------------------
// Function:  ~x86Instruction
// Parameters: None
// Special Notes: None
// --------------------------------------------------------------------------------------
x86Instruction::~x86Instruction()
{

}

// --------------------------------------------------------------------------------------
// Function:  PopulateInstruction
// Parameters: 
//   (I) firstByte - The first byte (prefix, primary opcode, etc.)
// Special Notes: None
// --------------------------------------------------------------------------------------
bool x86Instruction::PopulateInstruction(uint8_t firstByte)
{
  bool success = true;
  const x86OpcodeMap* opcode = &x86OpcodeMap::OpcodeMap[firstByte];

#if _DEBUG // Debug for specific addresses
  int x = 0;
  switch (RelativeAddress + CurrentOffset - 1)
  {
  case 0x1F0FFE:
    x = 1;
    break;
  }
#endif

  try
  { 
    // We need to check for prefixes..
    if (Mnemonic::PFIX == opcode->_Mnemonic)
    { 
      switch (firstByte)
      {
      case OpcodePrefix::PFIX_WAIT:
        Description.push_back(MnemonicStrings[Mnemonic::WAIT]);
        Prefix = static_cast<OpcodePrefix>(firstByte);
        break;
      case OpcodePrefix::PFIX_LOCK:
        Description.push_back(MnemonicStrings[Mnemonic::LOCK]);
        Prefix = static_cast<OpcodePrefix>(firstByte);
        break;
      case OpcodePrefix::PFIX_REPNZ:
        Description.push_back(MnemonicStrings[Mnemonic::REPNZ]);
        Prefix = static_cast<OpcodePrefix>(firstByte);
        break;
      case OpcodePrefix::PFIX_REPZ:
        Description.push_back(MnemonicStrings[Mnemonic::REPZ]);
        Prefix = static_cast<OpcodePrefix>(firstByte);
        break;
      case OpcodePrefix::ES_OVERRIDE:
      case OpcodePrefix::CS_OVERRIDE:
      case OpcodePrefix::SS_OVERRIDE:
      case OpcodePrefix::DS_OVERRIDE:
      case OpcodePrefix::FS_OVERRIDE:
      case OpcodePrefix::GS_OVERRIDE:
      case OpcodePrefix::OPERAND_SIZE:
      case OpcodePrefix::ADDRESS_SIZE:
        Prefix = static_cast<OpcodePrefix>(firstByte);
        break;
      default:
        Prefix = OpcodePrefix::NO_PREFIX;
      }

      if (OpcodePrefix::NO_PREFIX != Prefix)
      {
        firstByte = GetNext8();
        Data.push_back(firstByte);

        // Update opcode
        opcode = &x86OpcodeMap::OpcodeMap[firstByte];
      }
    }

    // Update opcode if this is a two-byte opcode.
    if (Mnemonic::TWO_OP == opcode->_Mnemonic)
    {
      firstByte = GetNext8();
      Data.push_back(firstByte);

      opcode = &x86OpcodeMap::TwoOpcodeMap0F[firstByte];
    }

    // Check for ModR/M or Opcode Extension existence.
    if (x86OpcodeMap::NONE != opcode->Fields)
    {
      // If OpcodeExtension is not specified, that means the Mnemonic is known
      // and so we continue with figuring out the Addressing mode and then allow
      // the ModRM class to perform the rest of the work.
      if (x86OpcodeMap::MODRM == opcode->Fields)
      {
        _Mnemonic = opcode->_Mnemonic;
        Description.push_back(MnemonicStrings[_Mnemonic]);

        uint8_t modRMByte = GetNext8();
        Data.push_back(modRMByte);

        x86ModRM modRM(modRMByte, Prefix);
        success = modRM.FillInstruction(opcode, this);
      }
      else
      {
        // We need to retrieve the ModRM structure in order to find the opcode
        // extension. Allow ModRM class to do the work..
        uint8_t modRMByte = GetNext8();
        Data.push_back(modRMByte);

        x86ModRM modRM(modRMByte, Prefix);
        success = modRM.FillExtendedInstruction(opcode, this);
      }
    }
    else
    {
      // There is no OpcodeExtension nor ModRM.
      _Mnemonic = opcode->_Mnemonic;
      Description.push_back(MnemonicStrings[_Mnemonic]);

      for (size_t i = 0; i < MAX_OPERANDS; ++i)
      {
        // If there was an error at some point, do not continue.
        if (false == success)
        {
          break;
        }

        REG reg = opcode->Operands[i];

        // Exit if not a register of any type..
        if (REG::NO_REG == opcode->Operands[i])
        {
          break;
        }

        // I might be wrong, but there are no registers to find unless
        // an ModRM/Opcode Extension exists
        switch (reg)
        {
          // Adjust explicit registers if operand prefix is set
          case REG::EAX:
          case REG::ECX:
          case REG::EDX:
          case REG::EBX:
          case REG::ESP:
          case REG::EBP:
          case REG::ESI:
          case REG::EDI:
          {
            if (OpcodePrefix::OPERAND_SIZE == Prefix)
            {
              reg = static_cast<REG>(static_cast<uint8_t>(reg) - 0x10);
            }

            Description.push_back(REGStrings[reg]);
          }
          break;

          // Adjust explicit registers if operand prefix is set
          case REG::AX:
          case REG::CX:
          case REG::DX:
          case REG::BX:
          case REG::SP:
          case REG::BP:
          case REG::SI:
          case REG::DI:
          {
            if (OpcodePrefix::OPERAND_SIZE == Prefix)
            {
              reg = static_cast<REG>(static_cast<uint8_t>(reg) + 0x10);
            }

            Description.push_back(REGStrings[reg]);
          }
          break;

          case REG::AL:
          case REG::CL:
          case REG::DL:
          case REG::BL:
          case REG::AH:
          case REG::CH:
          case REG::BH:
          case REG::DH:
          {
            Description.push_back(REGStrings[reg]);
          }
          break;

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
          {
            Description.push_back(REGStrings[reg]);
          }
          break;

          // Retrieve immediate8
          case REG::I8:
          {
            int8_t imm8 = GetNext8();
            AddData(reinterpret_cast<char*>(&imm8), 1);

            char str[4] = { 0 };
            sprintf_s(str,
                     "%s%02X",
                     imm8 < 0 ? "-" : "",
                     abs(imm8));
            Description.push_back(str);
          }
          break;

          // Retrieve immediate16
          case REG::I16:
          {
            int16_t imm16 = GetNext16();
            AddData(reinterpret_cast<char*>(&imm16), 2);

            char str[10] = { 0 };
            sprintf_s(str,
                      "%s%02X",
                      imm16 < 0 ? "-" : "",
                      abs(imm16));
            Description.push_back(str);
          }
          break;

          // Retrieve Immediate
          case REG::I16_32:
          {
            if (OpcodePrefix::OPERAND_SIZE == Prefix)
            {
              int16_t imm16 = GetNext16();
              AddData(reinterpret_cast<char*>(&imm16), 2);

              char str[6] = { 0 };
              sprintf_s(str,
                        "%s%04X",
                        imm16 < 0 ? "-" : "",
                        abs(imm16));
              Description.push_back(str);
            }
            else
            {
              uint32_t imm32 = GetNext32();
              AddData(reinterpret_cast<char*>(&imm32), 4);

              char str[10] = { 0 };
              sprintf_s(str, "%08X", imm32);
              Description.push_back(str);
            }
          }
          break;

          // Retrieve Relative
          case REG::REL8:
          {
            int8_t imm8 = GetNext8();
            AddData(reinterpret_cast<char*>(&imm8), 1);

            uint32_t relativeAddress = RelativeAddress +
                                       static_cast<uint32_t>(CurrentOffset) +
                                       imm8;

            char str[9] = { 0 };
            sprintf_s(str, "%08X", relativeAddress);
            Description.push_back(str);
          }
          break;

          // Retrieve Relative
          case REG::REL16:
          {
            int16_t imm16 = GetNext16();
            AddData(reinterpret_cast<char*>(&imm16), 2);

            uint32_t relativeAddress = RelativeAddress +
                                       static_cast<uint32_t>(CurrentOffset) +
                                       imm16;

            char str[9] = { 0 };
            sprintf_s(str, "%08X", relativeAddress);
            Description.push_back(str);
          }
          break;

          // Retrieve Relative 16/32
          case REG::REL16_32:
          {
            if (OpcodePrefix::OPERAND_SIZE == Prefix)
            {
              int16_t imm16 = GetNext16();
              AddData(reinterpret_cast<char*>(&imm16), 2);

              uint32_t relativeAddress = RelativeAddress +
                                         static_cast<uint32_t>(CurrentOffset) +
                                         imm16;

              char str[9] = { 0 };
              sprintf_s(str, "%08X", relativeAddress);
              Description.push_back(str);
            }
            else
            {
              int32_t imm32 = GetNext32();
              AddData(reinterpret_cast<char*>(&imm32), 4);

              uint32_t relativeAddress = RelativeAddress +
                                         static_cast<uint32_t>(CurrentOffset) +
                                         imm32;

              char str[9] = { 0 };
              sprintf_s(str, "%08X", relativeAddress);
              Description.push_back(str);
            }
          }
          break;

          // Retrieve FAR 16/32
          case REG::FAR16_32:
          {
            if (OpcodePrefix::OPERAND_SIZE == Prefix)
            {
              int16_t imm16 = GetNext16();
              AddData(reinterpret_cast<char*>(&imm16), 2);

              char str[6] = { 0 };
              sprintf_s(str,
                        "%s%04X",
                        imm16 < 0 ? "-" : "",
                        abs(imm16));
              Description.push_back(str);
            }
            else
            {
              uint32_t imm32 = GetNext32();
              AddData(reinterpret_cast<char*>(&imm32), 4);

              char str[10] = { 0 };
              sprintf_s(str, "%08X", imm32);
              Description.push_back(str);
            }
          }
          break;

          // Retrieve MOffset 16/32
          case REG::MO_16_32:
          case REG::MO_8:
          {
            uint32_t imm32 = GetNext32();
            AddData(reinterpret_cast<char*>(&imm32), 4);

            char str[12] = { 0 };
            sprintf_s(str, "[%08X]", imm32);

            std::string operand = str;
            x86ModRM modRM(0, Prefix);
            modRM.AppendSegmentOverride(operand);

            Description.push_back(operand);
          }
          break;

          default: // error
            throw x86DException(x86DException::INVALID_REG_MAP,
                                GetRelativeAddress(),
                                true);
        }
      }
    }
  }
  catch (x86DException& exception)
  {
    exception.PrintException();
    success = !exception.Fatal;

    // Set Mnemonic to DB for cleanup
    _Mnemonic = Mnemonic::DB;
  }

  // If Mnemonic was not updated, set default "mnemonic".
  if (Mnemonic::DB == _Mnemonic)
  {
    Description.clear();
    Description.push_back("DB");
    
    char str[4] = { 0 };
    sprintf_s(str, "%02X", Data[0]);
    Description.push_back(str);

    // Cleanup data and offset
    size_t bCnt = 0;
    while (1 < Data.size())
    {
      ++bCnt;
      Data.erase(Data.begin() + 1);
    }

    CurrentOffset -= bCnt;
  }

  return success;
}