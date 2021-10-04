#pragma once
#include "x86OpcodeMap.h"
#include <stdint.h>

// Forward declarations
class x86Instruction;
class x86OpcodeMap;

// This class provides utility functions to process ModRM
class x86ModRM
{
public:

  bool FillInstruction(const x86OpcodeMap* opcode, 
                       x86Instruction* instruction);
  bool FillExtendedInstruction(const x86OpcodeMap* opcode,
                               x86Instruction* instruction);
  void AppendSegmentOverride(std::string& operand) const;
  x86ModRM(uint8_t modRM, OpcodePrefix prefix);
  ~x86ModRM();

private:

  bool GetModRMOperands(x86Instruction* instruction,
                        const REG* operands, 
                        size_t numOperands,
                        bool ignoreOverride = false) const;
  bool GetFPOperands(x86Instruction* instruction, REG operand) const;
  bool TranslateRegister(x86Instruction* instruction, 
                         REG operand, 
                         std::string& operandStr,
                         bool ignoreOverride = false) const;

  uint8_t ModRM;
  uint8_t Mod;
  uint8_t RegOpcode;
  uint8_t RM;
  OpcodePrefix Prefix;
};
