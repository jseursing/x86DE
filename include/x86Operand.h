#pragma once
#include <stdint.h>

// -----------------------------------------------------------------------
// Mod R/M             (0..1)
//  Format: [AA][RR R][MMM]
//          A = Mod
//          R = Register/Opcode
//          M = Memory (RM)
//          MOD + RM sets second operand in two operand instruction  or
//          only operand in instruction
//
// SIB                 (0..1)
// Format:  [SS][III][BBB]
//          S = Scale  (n)
//          I = Index (REG2)
//          B + Base (REG1)
//          MOD = size of displacement
//          [(disp) + base + index*scale]

enum RegSize
{
  REG8    = 0,
  REG16   = 1,
  REG32   = 2,
  REGMM   = 3,
  REGXMM  = 4,
  REGCR   = 5,
  REGDR   = 6,
  SEGMENT = 7
};

enum REG
{
  // REG8 Addressing Mode
  AL = 0x00, 
  CL = 0x01,
  DL = 0x02,
  BL = 0x03,
  AH = 0x04,
  CH = 0x05,
  DH = 0x06,
  BH = 0x07,

  // REG16 Addressing Mode
  AX = 0x10,
  CX = 0x11,
  DX = 0x12,
  BX = 0x13,
  SP = 0x14,
  BP = 0x15,
  SI = 0x16,
  DI = 0x17,

  // REG32 Addressing Mode   
  EAX = 0x20, 
  ECX = 0x21,
  EDX = 0x22,
  EBX = 0x23,
  ESP = 0x24,
  EBP = 0x25,
  ESI = 0x26,
  EDI = 0x27,

  // REG64 Addressing Mode
  RAX = 0x30,
  RCX = 0x31,
  RDX = 0x32,
  RBX = 0x33,
  RSP = 0x34,
  RBP = 0x35,
  RSI = 0x36,
  RDI = 0x37,

  // 80-Bit x87
  ST0 = 0x40,
  ST1,
  ST2,
  ST3,
  ST4,
  ST5,
  ST6,
  ST7,

  // 64-Bit MMX
  MMX0,
  MMX1,
  MMX2,
  MMX3,
  MMX4,
  MMX5,
  MMX6,
  MMX7,

  // 128-Bit MMX
  XMM0,
  XMM1,
  XMM2,
  XMM3,
  XMM4,
  XMM5,
  XMM6,
  XMM7,
  XMM8,
  XMM9,
  XMM10,
  XMM11,
  XMM12,
  XMM13,
  XMM14,
  XMM15,

  // 256-Bit MMX
  YMM0,
  YMM1,
  YMM2,
  YMM3,
  YMM4,
  YMM5,
  YMM6,
  YMM7,
  YMM8,
  YMM9,
  YMM10,
  YMM11,
  YMM12,
  YMM13,
  YMM14,
  YMM15,

  // 16-Bit SEGMENT Registers
  DS,  // Code (Default)
  ES,  // Stack
  FS,  // Data
  GS,  // Data
  SS,  // Data
  CS,  // Date
  IP, 

  // 32-Bit Control
  CR0,
  CR1,
  CR2,
  CR3,
  CR4,
  CR5,
  CR6,
  CR7,
  CR8,
  CR9,
  CR10,
  CR11,
  CR12,
  CR13,
  CR14,
  CR15,

  // 32-Bit Debug
  DR0,
  DR1,
  DR2,
  DR3,
  DR4,
  DR5,
  DR6,
  DR7,
  DR8,
  DR9,
  DR10,
  DR11,
  DR12,
  DR13,
  DR14,
  DR15,

  // -----------------------------------------------------------------------
  // ModRM 16-bit Operands
  // -----------------------------------------------------------------------
  // 16-Bit Memory (No 32-bit memory address prefix)
  // MMM   AA=00       AA=01           AA=10            AA=11  SREG
  // ---   -----       ----------      ------------     -----  ----
  // 000   [BX + SI]   [BX + SI + d8]  [BX + SI + d16]  AX     DS
  // 001   [BX + DI]   [BX + DI + d8]  [BX + DI + d16]  BX     DS
  // 010   [BP + SI]   [BP + SI + d8]  [BP + SI + d16]  CX     SS
  // 011   [BP + DI]   [BP + DI + d8]  [BP + DI + d16]  DX     SS
  // 100   [SIB]       [SI + d8]       [SI + d16]       SP     DS
  // 101   [u16]       [DI + d8]       [SI + d16]       BP     DS
  // 110   [u16]       [BP + d8]       [BP + d16]       SI     SS
  // 111   [BX]        [BX + d8]       [BX + d16]       DI     DS
  // Note: MMM = 110, MM = 0: Default Sreg is DS 
  BX_SI,     
  BX_DI,     
  BP_SI,     
  BP_DI,     
  _SI,    
  _DI,    
  _I16,   
  _BX,

  BX_SI_D8,  
  BX_DI_D8,  
  BP_SI_D8,  
  BP_DI_D8,  
  SI_D8,  
  DI_D8,  
  BP_D8,  
  BX_D8,
  
  BX_SI_D16, 
  BX_DI_D16, 
  BP_SI_D16, 
  BP_DI_D16, 
  SI_D16,   
  // SI_D16
  BP_D16, 
  BX_D16,

  // -----------------------------------------------------------------------
  // ModRM 32-bit Operands
  // -----------------------------------------------------------------------
  // 32-Bit Memory (has 0x67 32-bit memory address prefix)
  // MMM  AA=00       AA=01           AA=10        AA=11  SREG
  // ---  -----       ----------      -----------  -----  ----
  // 000  [EAX]       [EAX + d8]      [EAX + d32]  EAX    DS
  // 001  [ECX]       [ECX + d8]      [ECX + d32]  ECX    DS
  // 010  [EDX]       [EDX + d8]      [EDX + d32]  EDX    DS
  // 011  [EBX]       [EBX + d8]      [EBX + d32]  EBX    DS
  // 100  [SIB]       [SIB + d8]      [SIB + d32]  ESP    SIB
  // 101  [i32]       [EBP + d8]      [EBP + d32]  EBP
  // 110  [ESI]       [ESI + d8]      [ESI + d32]  ESI
  // 111  [EDI]       [EDI + d8]      [EDI + d32]  EDI
  _EAX,    
  _ECX,    
  _EDX,    
  _EBX,    
  _SIB,    
  _U32,   
  _ESI,    
  _EDI,

  EAX_D8,  
  ECX_D8,  
  EDX_D8,  
  EBX_D8,  
  // _SIB         
  EBP_D8,  
  ESI_D8,  
  EDI_D8,

  EAX_D32, 
  ECX_D32, 
  EDX_D32, 
  EBX_D32,
  // _SIB          
  EBP_D32, 
  ESI_D32, 
  EDI_D32,

  // -----------------------------------------------------------------------
  // SIB (Base = R32), N = 2 ^ SS
  // III  SREG  MOD=00         MOD=01             MOD=10               MOD=11             
  // ---  ----  -----          -----              -----                -----           
  // 000        [R32 + EAX^N]  [R8 + EAX*N + I8]  [R32 + EAX*N + I32]  ERROR  
  // 001        [R32 + ECX^N]  [R8 + EBX*N + I8]  [R32 + EBX*N + I32]  ERROR
  // 010        [R32 + EBX^N]  [R8 + ECX*N + I8]  [R32 + ECX*N + I32]  ERROR 
  // 011        [R32 + EDX^N]  [R8 + EDX*N + I8]  [R32 + EDX*N + I32]  ERROR
  // 100        ERROR          ERROR              ERROR                ERROR
  // 101      ? [R32 + EBP^N]  [R8 + EBP*N + I8]  [R32 + EBP*N + I32]  ERROR 
  // 110        [R32 + ESI^N]  [R8 + ESI*N + I8]  [R32 + ESI*N + I32]  ERROR 
  // 111        [R32 + EDI^N]  [R8 + EDI*N + I8]  [R32 + EDI*N + I32]  ERROR
  //
  //
  // If BASE == 101 and MOD = 00
  // III  SREG  AA=00                          
  // ---  ----  -----                        
  // 000        [EAX*N + I32] 
  // 001        [EDX*N + I32] 
  // 010        [EDX*N + I32] 
  // 011        [EBX*N + I32] 
  // 100        ERROR or ESP?
  // 101        [EBP*N + I32] 
  // 110        [ESI*N + I32] 
  // 111        [EDI*N + I32] 
  //
  R32_EAX_N, 
  R32_ECX_N,
  R32_EDX_N,
  R32_EBX_N, 
  R32_ESP_N,
  R32_EBP_N,
  R32_ESI_N, 
  R32_EDI_N,

  R32_EAX_N_D8,
  R32_ECX_N_D8,
  R32_EDX_N_D8,
  R32_EBX_N_D8,
  R32_ESP_N_D8,
  R32_EBP_N_D8,
  R32_ESI_N_D8,
  R32_EDI_N_D8,

  R32_EAX_N_D32,
  R32_ECX_N_D32,
  R32_EDX_N_D32,
  R32_EBX_N_D32,
  R32_ESP_N_D32,
  R32_EBP_N_D32,
  R32_ESI_N_D32,
  R32_EDI_N_D32,
  
  EAX_N_D32,
  ECX_N_D32,
  EDX_N_D32,
  EBX_N_D32,
  ESP_N_D32,
  EBP_N_D32,
  ESI_N_D32,
  EDI_N_D32,

  // -----------------------------------------------------------------------
  // Float/Double Operands
  // -----------------------------------------------------------------------
  STi,
  M16_INT,
  M32_FP,
  M64_FP,
  M80_DEC,

  // -----------------------------------------------------------------------
  // Misc.
  // -----------------------------------------------------------------------
  ERROR,
  MAX_REGISTER,

  // -----------------------------------------------------------------------
  // These constants are used for the OpcodeMap/SREG SIB
  // -----------------------------------------------------------------------
  R8,
  R16,
  R16_32,
  R32,
  I8,
  I16,
  I16_32,
  REL8,
  REL16,
  REL16_32,
  MMX,
  XMM,
  YMM,
  M8,
  M16,
  M16_32,
  M32_256,
  M64_128,
  M64_256,
  M128_256,
  M64,
  M32,
  CR,
  DR,
  SIB,
  SREG,
  FAR16_32,
  MO_8,
  MO_16_32,
  NO_REG
};

static const char* REGStrings[REG::MAX_REGISTER] =
{
  // -----------------------------
  // BIT_8 Addressing Mode
  // -----------------------------
  "AL", 
  "CL", 
  "DL", 
  "BL", 
  "AH", 
  "CH", 
  "DH", 
  "BH",
  /* Padding */ "", "", "", "", "", "", "", "",

  // -----------------------------
  // REG16 Addressing Mode
  // -----------------------------
  "AX", 
  "CX", 
  "DX", 
  "BX", 
  "SP", 
  "BP", 
  "SI", 
  "DI",         
  /* Padding */ "", "", "", "", "", "", "", "",

  // -----------------------------
  // REG32 Addressing Mode
  // -----------------------------
  "EAX", 
  "ECX",
  "EDX", 
  "EBX", 
  "ESP", 
  "EBP", 
  "ESI", 
  "EDI", 
  /* Padding */ "", "", "", "", "", "", "", "",

  // -----------------------------
  // REG64 Addressing Mode
  // -----------------------------
  "RAX",
  "RCX",
  "RDX",
  "RBX",
  "RSP",
  "RBP",
  "RSI",
  "RDI",
  /* Padding */ "", "", "", "", "", "", "", "",

  // -----------------------------
  // 80-Bit x87
  // -----------------------------
  "ST0",
  "ST1",
  "ST2",
  "ST3",
  "ST4",
  "ST5",
  "ST6",
  "ST7",

  // -----------------------------
  // 64-Bit MMX
  // -----------------------------
  "MMX0",
  "MMX1",
  "MMX2",
  "MMX3",
  "MMX4",
  "MMX5",
  "MMX6",
  "MMX7",

  // -----------------------------
  // 128-Bit MMX
  // -----------------------------
  "XMM0",
  "XMM1",
  "XMM2",
  "XMM3",
  "XMM4",
  "XMM5",
  "XMM6",
  "XMM7",
  "XMM8",
  "XMM9",
  "XMM10",
  "XMM11",
  "XMM12",
  "XMM13",
  "XMM14",
  "XMM15",

  // -----------------------------
  // 256-Bit MMX
  // -----------------------------
  "YMM0",
  "YMM1",
  "YMM2",
  "YMM3",
  "YMM4",
  "YMM5",
  "YMM6",
  "YMM7",
  "YMM8",
  "YMM9",
  "YMM10",
  "YMM11",
  "YMM12",
  "YMM13",
  "YMM14",
  "YMM15",

  // -----------------------------
  // Segment Registers
  // -----------------------------
  "DS", 
  "ES", 
  "FS", 
  "GS", 
  "SS", 
  "CS", 
  "IP",   

  // -----------------------------
  // 32-Bit Control
  // -----------------------------
  "CR0",
  "CR1",
  "CR2",
  "CR3",
  "CR4",
  "CR5",
  "CR6",
  "CR7",
  "CR8",
  "CR9",
  "CR10",
  "CR11",
  "CR12",
  "CR13",
  "CR14",
  "CR15",

  // -----------------------------
  // 32-Bit Debug
  // -----------------------------
  "DR0",
  "DR1",
  "DR2",
  "DR3",
  "DR4",
  "DR5",
  "DR6",
  "DR7",
  "DR8",
  "DR9",
  "DR10",
  "DR11",
  "DR12",
  "DR13",
  "DR14",
  "DR15",
           
  // -----------------------------
  // ModRM 16-bit Operands
  // -----------------------------
  "[BX+SI]",  
  "[BX+DI]",  
  "[BP+SI]",  
  "[BP+DI]",  
  "[SI]",  
  "[DI]",  
  /*I16 */"", 
  "[BX]",

  "BX+SI ",   
  "BX+DI ",   
  "BP+SI ",  
  "BP+DI ",   
  "SI",   
  "DI",        
  "BP", 
  "BX",

  "BX+SI",   
  "BX+DI",   
  "BP+SI",   
  "BP+DI",   
  "SI",     
//"SI",
  "BP", 
  "BX",

  // -----------------------------
  // ModRM 32-bit Operands
  // -----------------------------
  "[EAX]",  
  "[ECX]",  
  "[EDX]",  
  "[EBX]",  
  /* _SIB */ "",  
  /* _U32 | */ "", 
  "[ESI]",  
  "[EDI]",

  "EAX",  
  "ECX",  
  "EDX",  
  "EBX",                         
  // _SIB
  "EBP",
  "ESI",   
  "EDI",

  "EAX",   
  "ECX",  
  "EDX",   
  "EBX",                         
  // _SIB
  "EBP",
  "ESI",   
  "EDI",

  // -----------------------------
  // SIB Operands
  // -----------------------------
  "EAX",
  "ECX",
  "EDX",
  "EBX",
  "ESP",
  "", /* SIB_SUB_TABLE */
  "ESI",
  "EDI",

  "EAX",
  "ECX",
  "EDX",
  "EBX",
  "ESP",
  "EBP",
  "ESI",
  "EDI",

  "EAX",
  "ECX",
  "EDX",
  "EBX",
  "ESP",
  "EBP",
  "ESI",
  "EDI",

  "EAX",
  "ECX",
  "EDX",
  "EBX",
  "ESP",
  "EBP",
  "ESI",
  "EDI",

  // -----------------------------------------------------------------------
  // Float/Double Operands
  // -----------------------------------------------------------------------
  "ST",
  "WORD PTR",
  "DWORD PTR",
  "QWORD PTR",
  "TWORD PTR",

  " ERROR "
};

static const uint32_t ModRegRegisterTable[8][SEGMENT + 1] =
{
// REG   8   16   32   SREG
// ---   --  --   --   ----
/* 000   AL  AX   EAX  DS */  {AL,   AX,   EAX,   MMX0,  XMM0,  CR0,  DR0,  DS},
/* 001   CL  CX   ECX  ES */  {CL,   CX,   ECX,   MMX1,  XMM1,  CR1,  DR1,  ES},
/* 010   DL  DX   EDX  FS */  {DL,   DX,   EDX,   MMX2,  XMM2,  CR2,  DR2,  FS},
/* 011   BL  BX   EBX  GS */  {BL,   BX,   EBX,   MMX3,  XMM3,  CR3,  DR3,  GS},
/* 100   AH  SP   ESP  SS */  {AH,   SP,   ESP,   MMX4,  XMM4,  CR4,  DR4,  SS},
/* 101   CH  BP   EBP  CS */  {CH,   BP,   EBP,   MMX5,  XMM5,  CR5,  DR5,  CS},
/* 110   DH  SI   ESI  IP */  {DH,   SI,   ESI,   MMX6,  XMM6,  CR6,  DR6,  IP},
/* 111   BH  DI   EDI     */  {BH,   DI,   EDI,   MMX7,  XMM7,  CR7,  DR7,  ERROR}
};

// Not too sure about how to fill this table out...
static const uint32_t ModReg8Table[8][5] =
{
  {_EAX,   EAX_D8,   EAX_D32,   AL,  DS},
  {_ECX,   ECX_D8,   ECX_D32,   CL,  DS},
  {_EDX,   EDX_D8,   EDX_D32,   DL,  DS},
  {_EBX,   EBX_D8,   EBX_D32,   BL,  DS},
  {_SIB,   _SIB,     _SIB,      AH,  SIB},
  {_U32,   EBP_D8,   EBP_D32,   CH,  SS},
  {_ESI,   ESI_D8,   ESI_D32,   DH,  DS},
  {_EDI,   EDI_D8,   EDI_D32,   BH,  DS}
};

static const uint32_t ModReg16Table[8][5] =
{
// MMM   AA=00       AA=01           AA=10            AA=11  SREG
// ---   -----       ----------      ------------     -----  ----
/* 000   [BX + SI]   [BX + SI + i8]  [BX + SI + i16]  AX     DS */  {_EAX,   EAX_D8,   EAX_D32,   AX,  DS},
/* 001   [BX + DI]   [BX + DI + i8]  [BX + DI + i16]  BX     DS */  {_ECX,   ECX_D8,   ECX_D32,   CX,  DS},
/* 010   [BP + SI]   [BP + SI + i8]  [BP + SI + i16]  CX     SS */  {_EDX,   EDX_D8,   EDX_D32,   DX,  DS},
/* 011   [BP + DI]   [BP + DI + i8]  [BP + DI + i16]  DX     SS */  {_EBX,   EBX_D8,   EBX_D32,   BX,  DS},
/* 100   [SIB]       [SI + i8]       [SI + i16]       SP     DS */  {_SIB,   _SIB,     _SIB,      SP,  SIB},
/* 101   [u16]       [DI + i8]       [SI + i16]       BP     DS */  {_U32,   EBP_D8,   EBP_D32,   BP,  SS},
/* 110   [??]        [BP + i8]       [BP + i16]       SI     SS */  {_ESI,   ESI_D8,   ESI_D32,   SI,  DS},
/* 111   [??]        [BX + i8]       [BX + i16]       DI     DS */  {_EDI,   EDI_D8,   EDI_D32,   DI,  DS}
};

static const uint32_t ModReg32Table[8][5] =
{
  // MMM  SREG  AA=00       AA=01           AA=10        AA=11  SREG
  // ---  ----  -----       ----------      -----------  -----  ----
  /* 000   DS   [EAX]       [EAX + d8]      [EAX + d32]  EAX    DS  */ {_EAX,   EAX_D8,   EAX_D32,   EAX,  DS},
  /* 001   DS   [ECX]       [ECX + d8]      [ECX + d32]  ECX    DS  */ {_ECX,   ECX_D8,   ECX_D32,   ECX,  DS}, 
  /* 010   DS   [EDX]       [EDX + d8]      [EDX + d32]  EDX    DS  */ {_EDX,   EDX_D8,   EDX_D32,   EDX,  DS},
  /* 011   DS   [EBX]       [EBX + d8]      [EBX + d32]  EBX    DS  */ {_EBX,   EBX_D8,   EBX_D32,   EBX,  DS}, 
  /* 100   SIB  [SIB]       [SIB + d8]      [SIB + d32]  ESP    SIB */ {_SIB,   _SIB,     _SIB,      ESP,  SIB},
  /* 101   SS   [u32]       [EBP + d8]      [EBP + d32]  EBP    SS  */ {_U32,   EBP_D8,   EBP_D32,   EBP,  SS}, 
  /* 110   DS   [ESI]       [ESI + d8]      [ESI + d32]  ESI    DS  */ {_ESI,   ESI_D8,   ESI_D32,   ESI,  DS},
  /* 111   DS   [EDI]       [EDI + d8]      [EDI + d32]  EDI    DS  */ {_EDI,   EDI_D8,   EDI_D32,   EDI,  DS} 
};

static const uint32_t SIBTable[8][4] =
{
  // SIB (Base = R32), N = 2 ^ SS
  // III  SREG  MOD=00         MOD=01             MOD=10               MOD=11             
  // ---  ----  -----          -----              -----                -----           
  /* 000        [R32 + EAX^N]  [R8 + EAX*N + I8]  [R32 + EAX*N + I32]  ERROR */ {R32_EAX_N, R32_EAX_N_D8, R32_EAX_N_D32, ERROR},
  /* 001        [R32 + ECX^N]  [R8 + ECX*N + I8]  [R32 + ECX*N + I32]  ERROR */ {R32_ECX_N, R32_ECX_N_D8, R32_ECX_N_D32, ERROR},
  /* 010        [R32 + EDX^N]  [R8 + EDX*N + I8]  [R32 + EDX*N + I32]  ERROR */ {R32_EDX_N, R32_EDX_N_D8, R32_EDX_N_D32, ERROR},
  /* 011        [R32 + EBX^N]  [R8 + EBX*N + I8]  [R32 + EBX*N + I32]  ERROR */ {R32_EBX_N, R32_EBX_N_D8, R32_EBX_N_D32, ERROR},
  /* 100        ERROR          ERROR              ERROR                ERROR */ {R32_ESP_N, R32_ESP_N_D8, R32_ESP_N_D32, ERROR},
  /* 101      ? [R32 + EBP^N]  [R8 + EBP*N + I8]  [R32 + EBP*N + I32]  ERROR */ {R32_EBP_N, R32_EBP_N_D8, R32_EBP_N_D32, ERROR},
  /* 110        [R32 + ESI^N]  [R8 + ESI*N + I8]  [R32 + ESI*N + I32]  ERROR */ {R32_ESI_N, R32_ESI_N_D8, R32_ESI_N_D32, ERROR},
  /* 111        [R32 + EDI^N]  [R8 + EDI*N + I8]  [R32 + EDI*N + I32]  ERROR */ {R32_EDI_N, R32_EDI_N_D8, R32_EDI_N_D32, ERROR},
};

static const uint32_t SIBSubTable[8] =
{
  // SIB (MOD == 0, Base == 101)
  // III        
  // ---        -------------
  /* 000        [EAX*N + I32] */ EAX_N_D32,
  /* 001        [ECX*N + I32] */ ECX_N_D32,
  /* 010        [EDX*N + I32] */ EDX_N_D32,
  /* 011        [EBX*N + I32] */ EBX_N_D32,
  /* 100        ERROR         */ ERROR,
  /* 101        [EBP*N + I32] */ EBP_N_D32,
  /* 110        [ESI*N + I32] */ ESI_N_D32,
  /* 111        [EDI*N + I32] */ EDI_N_D32
};