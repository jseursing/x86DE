#pragma once
#include "x86Mnemonic.h"
#include "x86Operand.h"
#include <string>
#include <vector>

// -----------------------------------------------------------------------
//
// Type                Size (Bytes):
// ------------------- -------------
// Instruction Prefix  (0..1)
// Address-size Prefix (0..1)
// Operand-size Prefix (0..1)
// Segment Prefix      (0..1)
// Opcode              (1..2)
// Mod R/M             (0..1)
//  Format: [AA][RR R][MMM]
//          A = Mod
//          R = Register/Opcode
//          M = Memory
// SIB                 (0..1)
//  Format: [SS][II I][B BB]
//          S = Scale
//          I = Index
//          B = Base
//          Address = BBB + III * (2 ^ SS)
// Displacement        (0, 1, 2, 4)
// Immediate           (0, 1, 2, 4)

// -----------------------------------------------------------------------
// MOD
// ---
// 00  Register Indirect Addressing Mode or SIB with no Displacement (R/M = 100)
// 01  1-Byte signed displacement after addressing mode byte(s)
// 10  4-byte signed displacement after addressing mode byte(s)
// 11  Register addressing mode

// -----------------------------------------------------------------------
// RRR  8B  16B  32B  SREG                                   See x86Regs.h
// ---  --  ---  ---  ----
// 000  AL  AX   EAX  DS
// 001  CL  CX   ECX  ES
// 010  DL  DX   EDX  FS
// 011  BL  BX   EBX  GS
// 100  AH  SP   ESP  SS
// 101  CH  BP   EBP  CS
// 110  DH  SI   ESI  IP
// 111  BH  DI   EDI
//

// -----------------------------------------------------------------------
// 16-Bit Memory (No 32-bit memory address prefix)
// MMM  SREG  AA=00       AA=01           AA=10            AA=11
// ---  ----  -----       ----------      ------------     -----
// 000   DS   [BX + SI]   [BX + SI + i8]  [BX + SI + i16]  AX
// 001   DS   [BX + DI]   [BX + DI + i8]  [BX + DI + i16]  CX
// 010   SS   [BP + SI]   [BP + SI + i8]  [BP + SI + i16]  DX
// 011   SS   [BP + DI]   [BP + DI + i8]  [BP + DI + i16]  BX
// 100   DS   [SI]        [SI + i8]       [SI + i16]       SP
// 101   DS   [DI]        [DI + i8]       [SI + i16]       BP
// 110   SS   [o16]       [BP + i8]       [BP + i16]       SI
// 111   DS   [BX]        [BX + i8]       [BX + i16]       DI
// Note: MMM = 110, MM = 0: Default Sreg is DS 

// -----------------------------------------------------------------------
// 32-Bit Memory (has 0x67 32-bit memory address prefix)
// MMM  SREG  AA=00       AA=01           AA=10        AA=11
// ---  ----  -----       ----------      -----------  -----
// 000   DS   [EAX]       [EAX+o8]        [EAX+o32]    EAX
// 001   DS   [ECX]       [ECX + i8]      [ECX + i32]  ECX
// 010   DS   [EDX]       [EDX + i8]      [EDX + i32]  EDX
// 011   DS   [EBX]       [EBX + i8]      [EBX + i32]  EBX 
// 100   SIB  [SIB]       [SIB + i8]      [SIB + i32]  ESP
// 101   SS   [o32]       [EBP + i8]      [EBP + i32]  EBP
// 110   DS   [ESI]       [ESI + i8]      [ESI + i32]  ESI
// 111   DS   [EDI]       [EDI + i8]      [EDI + i32]  EDI

// -----------------------------------------------------------------------
// Scale Index Base (SIB)
// BBB  SREG  REG 
// ---  ----  ---  
// 000  DS    EAX
// 001  DS    ECX
// 010  DS    EDX
// 011  DS    EBX
// 100  SS    ESP
// 101  DS    o32  if MM = 00 (Postbyte) else :
//      SS    EBP        
// 110  SS    ESI
// 111  DS    EDI
//
// III  REG   NOTE
// ---  ---   ----
// 000  EAX
// 001  ECX
// 010  EDX
// 011  EBX
// 100  ???
// 101  EBP
// 110  ESI
// 111  EDI
//
// SS : 2 ^ (ss)


// Constants
#define MAX_OPERANDS 4

// Forward declarations
class x86OpcodeMap;


// This class represents an object which contains the operator
// and operand for the given offset.
class x86Instruction
{
public:
  
  int8_t GetNext8();
  int16_t GetNext16();
  int32_t GetNext32();
  int8_t PeekNext8() const;

  void SetMnemonic(Mnemonic mnem);
  Mnemonic GetMnemonic() const;
  void SetOperand(REG operand, size_t operandIdx);
  REG GetOperand(size_t operandIdx) const;
  void AddData(char* data, size_t len);
  std::vector<uint8_t>& GetData();
  void AddDescription(std::string desc);
  std::vector<std::string>& GetDescription();

  std::string BuildInstruction() const;
  uintptr_t GetRelativeAddress() const;
  x86Instruction(char* buffer,
                 size_t& offset, 
                 size_t maxLength, 
                 uint32_t relativeAddr,
                 bool& success);
  ~x86Instruction();

private:

  bool PopulateInstruction(uint8_t firstByte);

  // Members filled in on construction
  char* Buffer;
  size_t CurrentOffset;
  size_t MaximumLength;
  uint32_t RelativeAddress;

  OpcodePrefix Prefix;
  Mnemonic _Mnemonic;
  REG Operands[MAX_OPERANDS];
  std::vector<std::string> Description;
  std::vector<uint8_t> Data;
};