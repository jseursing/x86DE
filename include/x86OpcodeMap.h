#pragma once
#include "x86Mnemonic.h"
#include "x86Operand.h"
#include <stdint.h>

// The following table defines a mapping of all opcodes and potential operands.
// Reference The HTML file in the include directory:
// "coder32 edition X86 Opcode and Instruction Reference 1.12.html"

class x86OpcodeMap
{
public:
  
  // Structure defining each entry of OpcodeMap table
  Mnemonic _Mnemonic;
  enum
  {
    NONE,
    MODRM,
    OPEXT
  } Fields;
  REG Operands[4];

  static const x86OpcodeMap OpcodeMap[];
  static const x86OpcodeMap TwoOpcodeMap0F[];

  // This structure is defined for Opcode Extensions table.
  // If a certain extension has multiple entries, place the
  // one with secondary opcodes first.
  struct ExtensionTable
  {
    Mnemonic mnemonic;
    uint8_t  secondaryOpcode; // 0 if not available
    uint8_t  extension;
    REG      Operands[4];
  };

  static const ExtensionTable* ExtensionTables[];

private:
  // Two-Opcode Extensions
  static const ExtensionTable Extension0F_0[];
  static const ExtensionTable Extension0F_1[];
  static const ExtensionTable Extension0F_2[];
  static const ExtensionTable Extension0F_3[];
  static const ExtensionTable Extension0F_4[];
  static const ExtensionTable Extension0F_5[];
  static const ExtensionTable Extension0F_6[];
  static const ExtensionTable Extension0F_7[];
  static const ExtensionTable Extension0F_8[];
  static const ExtensionTable Extension0F_9[];
  static const ExtensionTable Extension0F_A[];
  static const ExtensionTable Extension0F_B[];

  // Single Opcode Extensions
  static const ExtensionTable ExtensionMap80[];
  static const ExtensionTable ExtensionMap81[];
  static const ExtensionTable ExtensionMap83[];
  static const ExtensionTable ExtensionMapC0[];
  static const ExtensionTable ExtensionMapC1[];
  static const ExtensionTable ExtensionMapD0[];
  static const ExtensionTable ExtensionMapD1[];
  static const ExtensionTable ExtensionMapD2[];
  static const ExtensionTable ExtensionMapD3[];
  static const ExtensionTable ExtensionMap4[];
  static const ExtensionTable ExtensionMap5[];
  static const ExtensionTable ExtensionMap6[];
  static const ExtensionTable ExtensionMap7[];
  static const ExtensionTable ExtensionMap8[];
  static const ExtensionTable ExtensionMap9[];
  static const ExtensionTable ExtensionMapA[];
  static const ExtensionTable ExtensionMapB[];
  static const ExtensionTable ExtensionMapC[];
  static const ExtensionTable ExtensionMapD[];
  static const ExtensionTable ExtensionMapE[];
  static const ExtensionTable ExtensionMapF[];
};

