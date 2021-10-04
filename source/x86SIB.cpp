#include "x86Instruction.h"
#include "x86OpcodeMap.h"
#include "x86SIB.h"
#include <stdio.h>


// --------------------------------------------------------------------------------------
// Function:  GetOperand
// Parameters: None
// Special Notes: None
// --------------------------------------------------------------------------------------
bool x86SIB::GetOperand(x86Instruction* instruction, std::string& operandStr)
{
  bool success = true;

  // First retrieve the base
  const char* baseStr = REGStrings[Base];
  const char* indexStr = REGStrings[Index];

  // Fill in the rest of the string based on the Index
  switch (Index)
  {
    case R32_EAX_N:
    case R32_EBX_N:
    case R32_ECX_N:
    case R32_EDX_N:
    case R32_ESP_N:
    case R32_EBP_N:
    case R32_ESI_N:
    case R32_EDI_N:
    {
      // Create base + index + scale description
      char description[64] = {0};
      sprintf_s(description, 
                (0 == strlen(baseStr) ? "[%s%s" :
                                        "[%s+%s"), 
                baseStr, indexStr);
      
      switch (Scale)
      {
      case 0:
      case 1:
        sprintf_s(description, "%s]", description);
        break;
      default:
        sprintf_s(description, "%s*%d]", description, Scale);
      }
      
      operandStr = description;
    }
    break;

    case R32_EAX_N_D8:
    case R32_EBX_N_D8:
    case R32_ECX_N_D8:
    case R32_EDX_N_D8:
    case R32_ESP_N_D8:
    case R32_EBP_N_D8:
    case R32_ESI_N_D8:
    case R32_EDI_N_D8:
    {
      // Create base + index + scale description
      char description[64] = { 0 };
      sprintf_s(description,
                (0 == strlen(baseStr) ? "[%s%s" :
                                        "[%s+%s"),
                baseStr, indexStr);

      switch (Scale)
      {
      case 0:
      case 1:
        sprintf_s(description, "%s", description);
        break;
      default:
        sprintf_s(description, "%s*%d", description, Scale);
      }

      // Append Immediate
      int8_t imm8 = instruction->GetNext8();
      instruction->AddData(reinterpret_cast<char*>(&imm8), 1);

      sprintf_s(description,
                "%s%s%02X]",
                description,
                imm8 < 0 ? "-" : "+",
                abs(imm8));
      operandStr = description;
    }
    break;

    case R32_EAX_N_D32:
    case R32_EBX_N_D32:
    case R32_ECX_N_D32:
    case R32_EDX_N_D32:
    case R32_ESP_N_D32:
    case R32_EBP_N_D32:
    case R32_ESI_N_D32:
    case R32_EDI_N_D32:
    {
      // Create base + index + scale description
      char description[64] = { 0 };
      sprintf_s(description,
                (0 == strlen(baseStr) ? "[%s%s" :
                                        "[%s+%s"),
                baseStr, indexStr);

      switch (Scale)
      {
        case 0:
        case 1:
          sprintf_s(description, "%s", description);
          break;
        default:
          sprintf_s(description, "%s*%d", description, Scale);
      }

      // Append Immediate
      int32_t imm32 = instruction->GetNext32();
      instruction->AddData(reinterpret_cast<char*>(&imm32), 4);

      sprintf_s(description,
                "%s%s%08X]",
                description,
                imm32 < 0 ? "-" : "+",
                abs(imm32));
      operandStr = description;
    }
    break;

    case EAX_N_D32:
    case ECX_N_D32:
    case EDX_N_D32:
    case EBX_N_D32:
    case ESP_N_D32:
    case EBP_N_D32:
    case ESI_N_D32:
    case EDI_N_D32:
    {
      // Create index + scale description
      char description[64] = { 0 };
      switch (Scale)
      {
      case 0:
      case 1:
        sprintf_s(description, "[%s", indexStr);
        break;
      default:
        sprintf_s(description, "[%s*%d", indexStr, Scale);
      }

      // Append Immediate
      int32_t imm32 = instruction->GetNext32();
      instruction->AddData(reinterpret_cast<char*>(&imm32), 4);

      sprintf_s(description,
                "%s%s%08X]",
                description,
                imm32 < 0 ? "-" : "+",
                abs(imm32));
      operandStr = description;
    }
    break;

    default:
      success = false;
  }

  return success;
}

// --------------------------------------------------------------------------------------
// Function:  x86SIB
// Parameters: None
// Special Notes: None
// --------------------------------------------------------------------------------------
x86SIB::x86SIB(uint8_t sib, uint8_t mod, OpcodePrefix prefix) :
  Scale(0),
  Index(REG::NO_REG),
  Base(REG::_SIB),
  Mod(mod),
  Prefix(prefix)
{
  // Scale 2 ^ N
  switch (sib >> 6) // **00 0000
  {
  case 0:
    Scale = 1;
    break;
  case 1:
    Scale = 2;
    break;
  case 2:
    Scale = 4;
    break;
  case 3:
    Scale = 8;
    break;
  }
  
  // Index 
  uint32_t index = (sib & 0x38) >> 3; // 00** *000
  Index = static_cast<REG>(SIBTable[index][Mod]);

  // Base Register
  uint32_t base = sib & 0x7;  // 0000 0***

  // If Mod == 00 and Base == 101, we have a special case. Update Index
  if ((0 == Mod) &&
      (5 == base))
  {
    Index = static_cast<REG>(SIBSubTable[index]);
  }

  // Base is only valid when Index != 4
  if (index != 4)
  {
    Base = static_cast<REG>(static_cast<uint32_t>(REG::EAX) + base);
  }
}

// --------------------------------------------------------------------------------------
// Function:  ~x86SIB
// Parameters: None
// Special Notes: None
// --------------------------------------------------------------------------------------
x86SIB::~x86SIB()
{

}