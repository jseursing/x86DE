#pragma once
#include "x86OpcodeMap.h"
#include <stdint.h>

// Forward declarations
class x86Instruction;
class x86OpcodeMap;

// This class provides utility functions to process SIB
class x86SIB
{
public:
  
  bool GetOperand(x86Instruction* instruction, std::string& operandStr);
  x86SIB(uint8_t sib, uint8_t mod, OpcodePrefix prefix);
  ~x86SIB();

private:

  uint8_t Scale;
  REG     Index;
  REG     Base;
  uint8_t Mod;
  OpcodePrefix Prefix;
};