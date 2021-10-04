#include "x86OpcodeMap.h"

// ---------------------------------------------------------------------------------
// Following the Coder32/64, if there is an m*, place the M-type REG,
// otherwise place the specific register.
//
const x86OpcodeMap x86OpcodeMap::OpcodeMap[] =
{
  // -------------------------------------------------------------------------------
  // Mnemonic | Sec. Opcode/ModRM/Ext | Opcode 1 | Opcode 2 | Opcode 3 | Opcode 4 
  // -------------------------------------------------------------------------------

  // 0x00 .. 0x0F
  {Mnemonic::ADD,    x86OpcodeMap::MODRM,   REG::M8,      REG::R8,        REG::NO_REG,   REG::NO_REG}, // 0x00
  {Mnemonic::ADD,    x86OpcodeMap::MODRM,  REG::M16_32,   REG::R16_32,    REG::NO_REG,   REG::NO_REG}, // 0x01
  {Mnemonic::ADD,    x86OpcodeMap::MODRM,  REG::R8,       REG::M8,        REG::NO_REG,   REG::NO_REG}, // 0x02
  {Mnemonic::ADD,    x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x03
  {Mnemonic::ADD,    x86OpcodeMap::NONE,   REG::AL,       REG::I8,        REG::NO_REG,   REG::NO_REG}, // 0x04
  {Mnemonic::ADD,    x86OpcodeMap::NONE,   REG::EAX,      REG::I16_32,    REG::NO_REG,   REG::NO_REG}, // 0x05
  {Mnemonic::PUSH,   x86OpcodeMap::NONE,   REG::ES,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x06
  {Mnemonic::POP,    x86OpcodeMap::NONE,   REG::ES,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x07
  {Mnemonic::OR,     x86OpcodeMap::MODRM,  REG::M8,       REG::R8,        REG::NO_REG,   REG::NO_REG}, // 0x08
  {Mnemonic::OR,     x86OpcodeMap::MODRM,  REG::M16_32,   REG::R16_32,    REG::NO_REG,   REG::NO_REG}, // 0x09
  {Mnemonic::OR,     x86OpcodeMap::MODRM,  REG::R8,       REG::M8,        REG::NO_REG,   REG::NO_REG}, // 0x0A
  {Mnemonic::OR,     x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x0B
  {Mnemonic::OR,     x86OpcodeMap::NONE,   REG::AL,       REG::I8,        REG::NO_REG,   REG::NO_REG}, // 0x0C
  {Mnemonic::OR,     x86OpcodeMap::NONE,   REG::EAX,      REG::I16_32,    REG::NO_REG,   REG::NO_REG}, // 0x0D
  {Mnemonic::PUSH,   x86OpcodeMap::NONE,   REG::CS,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x0E
  {Mnemonic::TWO_OP, x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x0F

  // 0x10 .. 0x1F
  {Mnemonic::ADC,    x86OpcodeMap::MODRM,   REG::M8,       REG::R8,       REG::NO_REG,   REG::NO_REG}, // 0x10
  {Mnemonic::ADC,    x86OpcodeMap::MODRM,   REG::M16_32,   REG::R16_32,   REG::NO_REG,   REG::NO_REG}, // 0x11
  {Mnemonic::ADC,    x86OpcodeMap::MODRM,   REG::R8,       REG::M8,       REG::NO_REG,   REG::NO_REG}, // 0x12
  {Mnemonic::ADC,    x86OpcodeMap::MODRM,   REG::R16_32,   REG::M16_32,   REG::NO_REG,   REG::NO_REG}, // 0x13
  {Mnemonic::ADC,    x86OpcodeMap::NONE,    REG::AL,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0x14
  {Mnemonic::ADC,    x86OpcodeMap::NONE,    REG::EAX,      REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0x15
  {Mnemonic::PUSH,   x86OpcodeMap::NONE,    REG::SS,       REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x16
  {Mnemonic::POP,    x86OpcodeMap::NONE,    REG::SS,       REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x17
  {Mnemonic::SBB,    x86OpcodeMap::MODRM,   REG::M8,       REG::R8,       REG::NO_REG,   REG::NO_REG}, // 0x18
  {Mnemonic::SBB,    x86OpcodeMap::MODRM,   REG::M16_32,   REG::R16_32,   REG::NO_REG,   REG::NO_REG}, // 0x19
  {Mnemonic::SBB,    x86OpcodeMap::MODRM,   REG::R8,       REG::M8,       REG::NO_REG,   REG::NO_REG}, // 0x1A
  {Mnemonic::SBB,    x86OpcodeMap::MODRM,   REG::R16_32,   REG::M16_32,   REG::NO_REG,   REG::NO_REG}, // 0x1B
  {Mnemonic::SBB,    x86OpcodeMap::NONE,    REG::AL,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0x1C
  {Mnemonic::SBB,    x86OpcodeMap::NONE,    REG::EAX,      REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0x1D
  {Mnemonic::PUSH,   x86OpcodeMap::NONE,    REG::DS,       REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x1E
  {Mnemonic::POP,    x86OpcodeMap::NONE,    REG::DS,       REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x1F

  // 0x20 .. 0x2F
  {Mnemonic::AND,    x86OpcodeMap::MODRM,   REG::M8,       REG::R8,       REG::NO_REG,   REG::NO_REG}, // 0x20
  {Mnemonic::AND,    x86OpcodeMap::MODRM,   REG::M16_32,   REG::R16_32,   REG::NO_REG,   REG::NO_REG}, // 0x21
  {Mnemonic::AND,    x86OpcodeMap::MODRM,   REG::R8,       REG::M8,       REG::NO_REG,   REG::NO_REG}, // 0x22
  {Mnemonic::AND,    x86OpcodeMap::MODRM,   REG::R16_32,   REG::M16_32,   REG::NO_REG,   REG::NO_REG}, // 0x23
  {Mnemonic::AND,    x86OpcodeMap::NONE,    REG::AL,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0x24
  {Mnemonic::AND,    x86OpcodeMap::NONE,    REG::EAX,      REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0x25
  {Mnemonic::PFIX,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x26 * ES_OVERRIDE
  {Mnemonic::DAA,    x86OpcodeMap::NONE,    REG::AL,       REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x27
  {Mnemonic::SUB,    x86OpcodeMap::MODRM,   REG::M8,       REG::R8,       REG::NO_REG,   REG::NO_REG}, // 0x28
  {Mnemonic::SUB,    x86OpcodeMap::MODRM,   REG::M16_32,   REG::R16_32,   REG::NO_REG,   REG::NO_REG}, // 0x29
  {Mnemonic::SUB,    x86OpcodeMap::MODRM,   REG::R8,       REG::M8,       REG::NO_REG,   REG::NO_REG}, // 0x2A
  {Mnemonic::SUB,    x86OpcodeMap::MODRM,   REG::R16_32,   REG::M16_32,   REG::NO_REG,   REG::NO_REG}, // 0x2B
  {Mnemonic::SUB,    x86OpcodeMap::NONE,    REG::AL,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0x2C
  {Mnemonic::SUB,    x86OpcodeMap::NONE,    REG::EAX,      REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0x2D
  {Mnemonic::PFIX,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x2E * CS_OVERRIDE
  {Mnemonic::DAS,    x86OpcodeMap::NONE,    REG::AL,       REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x2F

  // 0x30 .. 0x3F
  {Mnemonic::XOR,    x86OpcodeMap::MODRM,   REG::M8,       REG::R8,       REG::NO_REG,   REG::NO_REG}, // 0x30
  {Mnemonic::XOR,    x86OpcodeMap::MODRM,   REG::M16_32,   REG::R16_32,   REG::NO_REG,   REG::NO_REG}, // 0x31
  {Mnemonic::XOR,    x86OpcodeMap::MODRM,   REG::R8,       REG::M8,       REG::NO_REG,   REG::NO_REG}, // 0x32
  {Mnemonic::XOR,    x86OpcodeMap::MODRM,   REG::R16_32,   REG::M16_32,   REG::NO_REG,   REG::NO_REG}, // 0x33
  {Mnemonic::XOR,    x86OpcodeMap::NONE,    REG::AL,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0x34
  {Mnemonic::XOR,    x86OpcodeMap::NONE,    REG::EAX,      REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0x35
  {Mnemonic::PFIX,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x36 * SS_OVERRIDE
  {Mnemonic::AAA,    x86OpcodeMap::NONE,    REG::AL,       REG::AH,       REG::NO_REG,   REG::NO_REG}, // 0x37
  {Mnemonic::CMP,    x86OpcodeMap::MODRM,   REG::M8,       REG::R8,       REG::NO_REG,   REG::NO_REG}, // 0x38
  {Mnemonic::CMP,    x86OpcodeMap::MODRM,   REG::M16_32,   REG::R16_32,   REG::NO_REG,   REG::NO_REG}, // 0x39
  {Mnemonic::CMP,    x86OpcodeMap::MODRM,   REG::R8,       REG::M8,       REG::NO_REG,   REG::NO_REG}, // 0x3A
  {Mnemonic::CMP,    x86OpcodeMap::MODRM,   REG::R16_32,   REG::M16_32,   REG::NO_REG,   REG::NO_REG}, // 0x3B
  {Mnemonic::CMP,    x86OpcodeMap::NONE,    REG::AL,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0x3C
  {Mnemonic::CMP,    x86OpcodeMap::NONE,    REG::EAX,      REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0x3D
  {Mnemonic::PFIX,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x3E
  {Mnemonic::AAS,    x86OpcodeMap::NONE,    REG::AL,       REG::AH,       REG::NO_REG,   REG::NO_REG}, // 0x3F

  // 0x40 .. 0x4F
  {Mnemonic::INC,    x86OpcodeMap::NONE,    REG::EAX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x40
  {Mnemonic::INC,    x86OpcodeMap::NONE,    REG::ECX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x41
  {Mnemonic::INC,    x86OpcodeMap::NONE,    REG::EDX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x42
  {Mnemonic::INC,    x86OpcodeMap::NONE,    REG::EBX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x43
  {Mnemonic::INC,    x86OpcodeMap::NONE,    REG::ESP,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x44
  {Mnemonic::INC,    x86OpcodeMap::NONE,    REG::EBP,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x45
  {Mnemonic::INC,    x86OpcodeMap::NONE,    REG::ESI,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x46
  {Mnemonic::INC,    x86OpcodeMap::NONE,    REG::EDI,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x47
  {Mnemonic::DEC,    x86OpcodeMap::NONE,    REG::EAX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x48
  {Mnemonic::DEC,    x86OpcodeMap::NONE,    REG::ECX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x49
  {Mnemonic::DEC,    x86OpcodeMap::NONE,    REG::EDX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x4A
  {Mnemonic::DEC,    x86OpcodeMap::NONE,    REG::EBX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x4B
  {Mnemonic::DEC,    x86OpcodeMap::NONE,    REG::ESP,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x4C
  {Mnemonic::DEC,    x86OpcodeMap::NONE,    REG::EBP,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x4D
  {Mnemonic::DEC,    x86OpcodeMap::NONE,    REG::ESI,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x4E
  {Mnemonic::DEC,    x86OpcodeMap::NONE,    REG::EDI,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x4F

  // 0x50 .. 0x5F
  {Mnemonic::PUSH,   x86OpcodeMap::NONE,    REG::EAX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x50
  {Mnemonic::PUSH,   x86OpcodeMap::NONE,    REG::ECX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x51
  {Mnemonic::PUSH,   x86OpcodeMap::NONE,    REG::EDX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x52
  {Mnemonic::PUSH,   x86OpcodeMap::NONE,    REG::EBX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x53
  {Mnemonic::PUSH,   x86OpcodeMap::NONE,    REG::ESP,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x54
  {Mnemonic::PUSH,   x86OpcodeMap::NONE,    REG::EBP,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x55
  {Mnemonic::PUSH,   x86OpcodeMap::NONE,    REG::ESI,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x56
  {Mnemonic::PUSH,   x86OpcodeMap::NONE,    REG::EDI,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x57
  {Mnemonic::POP,    x86OpcodeMap::NONE,    REG::EAX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x58
  {Mnemonic::POP,    x86OpcodeMap::NONE,    REG::ECX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x59
  {Mnemonic::POP,    x86OpcodeMap::NONE,    REG::EDX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x5A
  {Mnemonic::POP,    x86OpcodeMap::NONE,    REG::EBX,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x5B
  {Mnemonic::POP,    x86OpcodeMap::NONE,    REG::ESP,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x5C
  {Mnemonic::POP,    x86OpcodeMap::NONE,    REG::EBP,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x5D
  {Mnemonic::POP,    x86OpcodeMap::NONE,    REG::ESI,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x5E
  {Mnemonic::POP,    x86OpcodeMap::NONE,    REG::EDI,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x5F

  // 0x60 .. 0x6F
  {Mnemonic::PUSHAD, x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x60
  {Mnemonic::POPAD,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x61
  {Mnemonic::BOUND,  x86OpcodeMap::MODRM,   REG::R16_32,   REG::M16_32,   REG::NO_REG,   REG::NO_REG}, // 0x62 
  {Mnemonic::ARPL,   x86OpcodeMap::MODRM,   REG::M16,      REG::R16,      REG::NO_REG,   REG::NO_REG}, // 0x63
  {Mnemonic::PFIX,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x64 * FS
  {Mnemonic::PFIX,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x65 * GS
  {Mnemonic::PFIX,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x66 * OPERAND_OVERRIDE
  {Mnemonic::PFIX,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x67 * ADDRESS_OVERRIDE
  {Mnemonic::PUSH,   x86OpcodeMap::NONE,    REG::I16_32,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x68
  {Mnemonic::IMUL,   x86OpcodeMap::MODRM,   REG::R16_32,   REG::M16_32,   REG::I16_32,   REG::NO_REG}, // 0x69
  {Mnemonic::PUSH,   x86OpcodeMap::NONE,    REG::I8,       REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x6A
  {Mnemonic::IMUL,   x86OpcodeMap::MODRM,   REG::R16_32,   REG::M16_32,   REG::I8,       REG::NO_REG}, // 0x6B
  {Mnemonic::INSB,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x6C
  {Mnemonic::INSW,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x6D
  {Mnemonic::OUTSB,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x6E
  {Mnemonic::OUTSW,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x6F

  // 0x70 .. 0x7F
  {Mnemonic::JO,     x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x70
  {Mnemonic::JNO,    x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x71
  {Mnemonic::JB,     x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x72
  {Mnemonic::JNB,    x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x73
  {Mnemonic::JZ,     x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x74
  {Mnemonic::JNZ,    x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x75
  {Mnemonic::JNA,    x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x76
  {Mnemonic::JA,     x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x77
  {Mnemonic::JS,     x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x78
  {Mnemonic::JNS,    x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x79
  {Mnemonic::JP,     x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x7A
  {Mnemonic::JNP,    x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x7B
  {Mnemonic::JL,     x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x7C
  {Mnemonic::JNL,    x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x7D
  {Mnemonic::JNG,    x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x7E
  {Mnemonic::JG,     x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x7F

  // 0x80 .. 0x8F
  {Mnemonic::EXT80,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x80
  {Mnemonic::EXT81,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x81
  {Mnemonic::EXT80,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x82
  {Mnemonic::EXT83, x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,     REG::NO_REG}, // 0x83
  {Mnemonic::TEST,   x86OpcodeMap::MODRM,   REG::M8,       REG::R8,       REG::NO_REG,   REG::NO_REG}, // 0x84
  {Mnemonic::TEST,   x86OpcodeMap::MODRM,   REG::M16_32,   REG::R16_32,   REG::NO_REG,   REG::NO_REG}, // 0x85
  {Mnemonic::XCHG,   x86OpcodeMap::MODRM,   REG::R8,       REG::M8,       REG::NO_REG,   REG::NO_REG}, // 0x86
  {Mnemonic::XCHG,   x86OpcodeMap::MODRM,   REG::R16_32,   REG::M16_32,   REG::NO_REG,   REG::NO_REG}, // 0x87
  {Mnemonic::MOV,    x86OpcodeMap::MODRM,   REG::M8,       REG::R8,       REG::NO_REG,   REG::NO_REG}, // 0x88
  {Mnemonic::MOV,    x86OpcodeMap::MODRM,   REG::M16_32,   REG::R16_32,   REG::NO_REG,   REG::NO_REG}, // 0x89
  {Mnemonic::MOV,    x86OpcodeMap::MODRM,   REG::R8,       REG::M8,       REG::NO_REG,   REG::NO_REG}, // 0x8A
  {Mnemonic::MOV,    x86OpcodeMap::MODRM,   REG::R16_32,   REG::M16_32,   REG::NO_REG,   REG::NO_REG}, // 0x8B
  {Mnemonic::MOV,    x86OpcodeMap::MODRM,   REG::M16_32,   REG::SREG,     REG::NO_REG,   REG::NO_REG}, // 0x8C
  {Mnemonic::LEA,    x86OpcodeMap::MODRM,   REG::R16_32,   REG::M16_32,   REG::NO_REG,   REG::NO_REG}, // 0x8D
  {Mnemonic::MOV,    x86OpcodeMap::MODRM,   REG::SREG,     REG::M16,      REG::NO_REG,   REG::NO_REG}, // 0x8E
  {Mnemonic::POP,    x86OpcodeMap::MODRM,   REG::M16_32,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x8F

  // 0x90 .. 0x9F
  {Mnemonic::NOP,    x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x90
  {Mnemonic::XCHG,   x86OpcodeMap::NONE,    REG::ECX,      REG::EAX,      REG::NO_REG,   REG::NO_REG}, // 0x91
  {Mnemonic::XCHG,   x86OpcodeMap::NONE,    REG::EDX,      REG::EAX,      REG::NO_REG,   REG::NO_REG}, // 0x92
  {Mnemonic::XCHG,   x86OpcodeMap::NONE,    REG::EBX,      REG::EAX,      REG::NO_REG,   REG::NO_REG}, // 0x93
  {Mnemonic::XCHG,   x86OpcodeMap::NONE,    REG::ESP,      REG::EAX,      REG::NO_REG,   REG::NO_REG}, // 0x94
  {Mnemonic::XCHG,   x86OpcodeMap::NONE,    REG::EBP,      REG::EAX,      REG::NO_REG,   REG::NO_REG}, // 0x95
  {Mnemonic::XCHG,   x86OpcodeMap::NONE,    REG::ESI,      REG::EAX,      REG::NO_REG,   REG::NO_REG}, // 0x96
  {Mnemonic::XCHG,   x86OpcodeMap::NONE,    REG::EDI,      REG::EAX,      REG::NO_REG,   REG::NO_REG}, // 0x97
  {Mnemonic::CWDE,   x86OpcodeMap::NONE,    REG::EAX,      REG::AX,       REG::NO_REG,   REG::NO_REG}, // 0x98
  {Mnemonic::CDQ,    x86OpcodeMap::NONE,    REG::EDX,      REG::EAX,      REG::NO_REG,   REG::NO_REG}, // 0x99
  {Mnemonic::CALLF,  x86OpcodeMap::NONE,    REG::FAR16_32, REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x9A
  {Mnemonic::WAIT,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x9B
  {Mnemonic::PUSHFD, x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x9C
  {Mnemonic::POPFD,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x9D
  {Mnemonic::SAHF,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x9E
  {Mnemonic::LAHF,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0x9E

  // 0xA0 .. 0xAF
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::AL,       REG::MO_8,     REG::NO_REG,   REG::NO_REG}, // 0xA0
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::EAX,      REG::MO_16_32, REG::NO_REG,   REG::NO_REG}, // 0xA1
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::MO_8,     REG::AL,       REG::NO_REG,   REG::NO_REG}, // 0xA2
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::MO_16_32, REG::EAX,      REG::NO_REG,   REG::NO_REG}, // 0xA3
  {Mnemonic::MOVSB,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xA4
  {Mnemonic::MOVSW,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xA5
  {Mnemonic::CMPSB,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xA6
  {Mnemonic::CMPSW,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xA7
  {Mnemonic::TEST,   x86OpcodeMap::NONE,    REG::AL,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0xA8
  {Mnemonic::TEST,   x86OpcodeMap::NONE,    REG::EAX,      REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0xA9
  {Mnemonic::STOSB,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xAA
  {Mnemonic::STOSW,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xAB
  {Mnemonic::LODSB,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xAC
  {Mnemonic::LODSW,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xAD
  {Mnemonic::SCASB,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xAE
  {Mnemonic::SCASW,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xAF

  // 0xB0 .. 0xBF
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::AL,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0xB0
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::CL,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0xB1
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::DL,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0xB2
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::BL,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0xB3
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::AH,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0xB4
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::CH,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0xB5
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::DH,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0xB6
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::BH,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0xB7
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::EAX,      REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0xB8
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::ECX,      REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0xB9
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::EDX,      REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0xBA
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::EBX,      REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0xBB
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::ESP,      REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0xBC
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::EBP,      REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0xBD
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::ESI,      REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0xBE
  {Mnemonic::MOV,    x86OpcodeMap::NONE,    REG::EDI,      REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0xBF

  // 0xC0 .. 0xCF
  {Mnemonic::EXTC0,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xC0
  {Mnemonic::EXTC1,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xC1
  {Mnemonic::RETN,   x86OpcodeMap::NONE,    REG::I16,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xC2
  {Mnemonic::RET,    x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xC3
  {Mnemonic::LES,    x86OpcodeMap::MODRM,   REG::R16_32,   REG::MO_16_32, REG::NO_REG,   REG::NO_REG}, // 0xC4
  {Mnemonic::LDS,    x86OpcodeMap::MODRM,   REG::R16_32,   REG::MO_16_32, REG::NO_REG,   REG::NO_REG}, // 0xC5
  {Mnemonic::MOV,    x86OpcodeMap::MODRM,   REG::M8,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0xC6
  {Mnemonic::MOV,    x86OpcodeMap::MODRM,   REG::M16_32,   REG::I16_32,   REG::NO_REG,   REG::NO_REG}, // 0xC7
  {Mnemonic::ENTER,  x86OpcodeMap::NONE,    REG::I16,      REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0xC8
  {Mnemonic::LEAVE,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xC9
  {Mnemonic::RETF,   x86OpcodeMap::NONE,    REG::I16,      REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xCA
  {Mnemonic::RETF,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xCB
  {Mnemonic::INT3,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xCC
  {Mnemonic::INT,    x86OpcodeMap::NONE,    REG::I8,       REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xCD
  {Mnemonic::INTO,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xCE
  {Mnemonic::IRETD,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xCF

  // 0xD0 .. 0xDF
  {Mnemonic::EXTD0,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xD0
  {Mnemonic::EXTD1,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xD1
  {Mnemonic::EXTD2,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xD2
  {Mnemonic::EXTD3,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xD3
  {Mnemonic::AMX,    x86OpcodeMap::NONE,    REG::I8,       REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xD4 // There's a secondary opcode..
  {Mnemonic::ADX,    x86OpcodeMap::NONE,    REG::I8,       REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xD5 // There's a secondary opcode..
  {Mnemonic::SALC,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xD6
  {Mnemonic::XLATB,  x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xD7
  {Mnemonic::EXT_4,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xD8
  {Mnemonic::EXT_5,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xD9
  {Mnemonic::EXT_6,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xDA
  {Mnemonic::EXT_7,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xDB
  {Mnemonic::EXT_8,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xDC
  {Mnemonic::EXT_9,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xDD
  {Mnemonic::EXT_A,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xDE
  {Mnemonic::EXT_B,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xDF

  // 0xE0 .. 0xEF
  {Mnemonic::LOOPNZ, x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xE0
  {Mnemonic::LOOPZ,  x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xE1
  {Mnemonic::LOOP,   x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xE2
  {Mnemonic::JCXZ,   x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xE3
  {Mnemonic::IN,     x86OpcodeMap::NONE,    REG::AL,       REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0xE4
  {Mnemonic::IN,     x86OpcodeMap::NONE,    REG::EAX,      REG::I8,       REG::NO_REG,   REG::NO_REG}, // 0xE5
  {Mnemonic::OUT,    x86OpcodeMap::NONE,    REG::I8,       REG::AL,       REG::NO_REG,   REG::NO_REG}, // 0xE6
  {Mnemonic::OUT,    x86OpcodeMap::NONE,    REG::I8,       REG::EAX,      REG::NO_REG,   REG::NO_REG}, // 0xE7
  {Mnemonic::CALL,   x86OpcodeMap::NONE,    REG::REL16_32, REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xE8
  {Mnemonic::JMP,    x86OpcodeMap::NONE,    REG::REL16_32, REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xE9
  {Mnemonic::JMPF,   x86OpcodeMap::NONE,    REG::FAR16_32, REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xEA
  {Mnemonic::JMP,    x86OpcodeMap::NONE,    REG::REL8,     REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xEB
  {Mnemonic::IN,     x86OpcodeMap::NONE,    REG::AL,       REG::DX,       REG::NO_REG,   REG::NO_REG}, // 0xEC
  {Mnemonic::IN,     x86OpcodeMap::NONE,    REG::EAX,      REG::DX,       REG::NO_REG,   REG::NO_REG}, // 0xED
  {Mnemonic::OUT,    x86OpcodeMap::NONE,    REG::DX,       REG::AL,       REG::NO_REG,   REG::NO_REG}, // 0xEE
  {Mnemonic::OUT,    x86OpcodeMap::NONE,    REG::DX,       REG::EAX,      REG::NO_REG,   REG::NO_REG}, // 0xEF
  
  // 0xF0 .. 0xFF
  {Mnemonic::PFIX,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xF0 * LOCK
  {Mnemonic::INT1,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xF1
  {Mnemonic::PFIX,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xF2 * REPNZ
  {Mnemonic::PFIX,   x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xF3 * REPZ
  {Mnemonic::HLT,    x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xF4
  {Mnemonic::CMC,    x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xF5
  {Mnemonic::EXT_C,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xF6
  {Mnemonic::EXT_D,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xF7
  {Mnemonic::CLC,    x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xF8
  {Mnemonic::STC,    x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xF9
  {Mnemonic::CLI,    x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xFA
  {Mnemonic::STI,    x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xFB
  {Mnemonic::CLD,    x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xFC
  {Mnemonic::STD,    x86OpcodeMap::NONE,    REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xFD
  {Mnemonic::EXT_E,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}, // 0xFE
  {Mnemonic::EXT_F,  x86OpcodeMap::OPEXT,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG,   REG::NO_REG}  // 0xFF
};

const x86OpcodeMap x86OpcodeMap::TwoOpcodeMap0F[] = // 0x0F
{
  // -------------------------------------------------------------------------------
  // Mnemonic | Sec. Opcode/ModRM/Ext | Opcode 1 | Opcode 2 | Opcode 3 | Opcode 4 
  // -------------------------------------------------------------------------------

  // 0x00 .. 0x0F
  {Mnemonic::OPF_0,  x86OpcodeMap::OPEXT,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x00
  {Mnemonic::OPF_1,  x86OpcodeMap::OPEXT,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x01
  {Mnemonic::LAR,    x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16,       REG::NO_REG,   REG::NO_REG}, // 0x02
  {Mnemonic::LSL,    x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16,       REG::NO_REG,   REG::NO_REG}, // 0x03
  {Mnemonic::DB,     x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x04
  {Mnemonic::DB,     x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x05
  {Mnemonic::CLTS,   x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x06
  {Mnemonic::DB,     x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x07
  {Mnemonic::INVD,   x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x08
  {Mnemonic::WBINVD, x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x09
  {Mnemonic::DB,     x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x0A
  {Mnemonic::UD2,    x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x0B
  {Mnemonic::DB,     x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x0C
  {Mnemonic::NOP,    x86OpcodeMap::MODRM,  REG::M16_32,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x0D
  {Mnemonic::DB,     x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x0E
  {Mnemonic::DB,     x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x0F

  // 0x10 .. 0x1F
  {Mnemonic::MOVUPS,   x86OpcodeMap::MODRM,  REG::XMM,      REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x10
  {Mnemonic::MOVUPS,   x86OpcodeMap::MODRM,  REG::M16_32,   REG::XMM,    REG::NO_REG,   REG::NO_REG}, // 0x11
  {Mnemonic::MOVHLPS,  x86OpcodeMap::MODRM,  REG::XMM,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x12
  {Mnemonic::MOVLPS,   x86OpcodeMap::MODRM,  REG::XMM,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x13
  {Mnemonic::UNPCKLPS, x86OpcodeMap::MODRM,  REG::M64_128,  REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x14
  {Mnemonic::UNPCKHPS, x86OpcodeMap::MODRM,  REG::M64_128,  REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x15
  {Mnemonic::MOVLHPS,  x86OpcodeMap::MODRM,  REG::XMM,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x16
  {Mnemonic::MOVHPS,   x86OpcodeMap::MODRM,  REG::XMM,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x17
  {Mnemonic::OPF_2,    x86OpcodeMap::OPEXT,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x18
  {Mnemonic::HINT_NOP, x86OpcodeMap::MODRM,  REG::M16_32,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x19
  {Mnemonic::HINT_NOP, x86OpcodeMap::MODRM,  REG::M16_32,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x1A
  {Mnemonic::HINT_NOP, x86OpcodeMap::MODRM,  REG::M16_32,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x1B
  {Mnemonic::HINT_NOP, x86OpcodeMap::MODRM,  REG::M16_32,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x1C
  {Mnemonic::HINT_NOP, x86OpcodeMap::MODRM,  REG::M16_32,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x1D
  {Mnemonic::HINT_NOP, x86OpcodeMap::MODRM,  REG::M16_32,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x1E
  {Mnemonic::OPF_3,    x86OpcodeMap::OPEXT,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x1F

  // 0x20 .. 0x2F
  {Mnemonic::MOV,      x86OpcodeMap::MODRM,  REG::R32,      REG::CR,        REG::NO_REG,   REG::NO_REG}, // 0x20
  {Mnemonic::MOV,      x86OpcodeMap::MODRM,  REG::R32,      REG::DR,        REG::NO_REG,   REG::NO_REG}, // 0x21
  {Mnemonic::MOV,      x86OpcodeMap::MODRM,  REG::CR,       REG::R32,       REG::NO_REG,   REG::NO_REG}, // 0x22
  {Mnemonic::MOV,      x86OpcodeMap::MODRM,  REG::DR,       REG::R32,       REG::NO_REG,   REG::NO_REG}, // 0x23
  {Mnemonic::DB,       x86OpcodeMap::MODRM,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x24
  {Mnemonic::DB,       x86OpcodeMap::MODRM,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x25
  {Mnemonic::DB,       x86OpcodeMap::MODRM,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x26
  {Mnemonic::DB,       x86OpcodeMap::MODRM,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x27
  {Mnemonic::MOVAPS,   x86OpcodeMap::MODRM,  REG::XMM0,      REG::XMM,      REG::NO_REG,   REG::NO_REG}, // 0x28
  {Mnemonic::MOVAPS,   x86OpcodeMap::MODRM,  REG::XMM0,      REG::XMM,      REG::NO_REG,   REG::NO_REG}, // 0x29
  {Mnemonic::CVTPI2PS, x86OpcodeMap::MODRM,  REG::MMX,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x2A
  {Mnemonic::MOVNTPS,  x86OpcodeMap::MODRM,  REG::XMM,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x2B
  {Mnemonic::CVTTPS2PI,x86OpcodeMap::MODRM,  REG::M64_128,  REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x2C
  {Mnemonic::CVTPS2PI, x86OpcodeMap::MODRM,  REG::M64_128,  REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x2D
  {Mnemonic::UCOMISS,  x86OpcodeMap::MODRM,  REG::XMM,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x2E
  {Mnemonic::COMISS,   x86OpcodeMap::MODRM,  REG::XMM,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x2F

  // 0x30 .. 0x3F
  {Mnemonic::WRMSR,    x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x30
  {Mnemonic::RDTSC,    x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x31
  {Mnemonic::RDMSR,    x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x32
  {Mnemonic::RDPMC,    x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x33
  {Mnemonic::SYSENTER, x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x34
  {Mnemonic::SYSEXIT,  x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x35
  {Mnemonic::DB,       x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x36
  {Mnemonic::GETSEC,   x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x37
  {Mnemonic::OPF_4,    x86OpcodeMap::OPEXT,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x38
  {Mnemonic::DB,       x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x39
  {Mnemonic::OPF_5,    x86OpcodeMap::OPEXT,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x3A
  {Mnemonic::DB,       x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x3B
  {Mnemonic::DB,       x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x3C
  {Mnemonic::DB,       x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x3D
  {Mnemonic::DB,       x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x3E
  {Mnemonic::DB,       x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x3F

  // 0x40 .. 0x4F
  {Mnemonic::CMOVO,    x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x40
  {Mnemonic::CMOVNO,   x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x41
  {Mnemonic::CMOVB,    x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x42
  {Mnemonic::CMOVNB,   x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x43
  {Mnemonic::CMOVZ,    x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x44
  {Mnemonic::CMOVNZ,   x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x45
  {Mnemonic::CMOVBE,   x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x46
  {Mnemonic::CMOVNBE,  x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x47
  {Mnemonic::CMOVS,    x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x48
  {Mnemonic::CMOVNS,   x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x49
  {Mnemonic::CMOVP,    x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x4A
  {Mnemonic::CMOVNP,   x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x4B
  {Mnemonic::CMOVL,    x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x4C
  {Mnemonic::CMOVNL,   x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x4D
  {Mnemonic::CMOVLE,   x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x4E
  {Mnemonic::CMOVNLE,  x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0x4F

  // 0x50 .. 0x5F (TODO..)
  {Mnemonic::MOVMSKPS, x86OpcodeMap::MODRM,  REG::R32,      REG::XMM,       REG::NO_REG,   REG::NO_REG}, // 0x50
  {Mnemonic::SQRTPS,   x86OpcodeMap::MODRM,  REG::XMM,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x51
  {Mnemonic::RSQRTPS,  x86OpcodeMap::MODRM,  REG::XMM,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x52
  {Mnemonic::RCPPS,    x86OpcodeMap::MODRM,  REG::XMM,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x53
  {Mnemonic::ANDPS,    x86OpcodeMap::MODRM,  REG::XMM,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x54
  {Mnemonic::ANDNPS,   x86OpcodeMap::MODRM,  REG::XMM,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x55
  {Mnemonic::ORPS,     x86OpcodeMap::MODRM,  REG::XMM,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x56
  {Mnemonic::XORPS,    x86OpcodeMap::MODRM,  REG::XMM,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x57
  {Mnemonic::ADDPS,    x86OpcodeMap::MODRM,  REG::XMM,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x58
  {Mnemonic::MULPS,    x86OpcodeMap::MODRM,  REG::XMM,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x59
  {Mnemonic::CVTPS2PD, x86OpcodeMap::MODRM,  REG::XMM,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x5A
  {Mnemonic::CVTDQ2PS, x86OpcodeMap::MODRM,  REG::XMM,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x5B
  {Mnemonic::SUBPS,    x86OpcodeMap::MODRM,  REG::XMM,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x5C
  {Mnemonic::MINPS,    x86OpcodeMap::MODRM,  REG::XMM,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x5D
  {Mnemonic::DIVPS,    x86OpcodeMap::MODRM,  REG::XMM,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x5E
  {Mnemonic::MAXPS,    x86OpcodeMap::MODRM,  REG::XMM,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x5F

  // 0x60 .. 0x6F (TODO..)
  {Mnemonic::PUNPCKLBW, x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x50
  {Mnemonic::PUNPCKLWD, x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x51
  {Mnemonic::PUNPCKLDQ, x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x52
  {Mnemonic::PACKSSWB,  x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x53
  {Mnemonic::PCMPGTB,   x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x54
  {Mnemonic::PCMPGTW,   x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x55
  {Mnemonic::PCMPGTD,   x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x56
  {Mnemonic::PACKUSWB,  x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x57
  {Mnemonic::PUNPCKHBW, x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x58
  {Mnemonic::PUNPCKHWD, x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x59
  {Mnemonic::PUNPCKHDQ, x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x5A
  {Mnemonic::PACKSSDW,  x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x5B
  {Mnemonic::PUNPCKLQDQ,x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x5C
  {Mnemonic::PUNPCKHQDQ,x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x5D
  {Mnemonic::MOVD,      x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x5E
  {Mnemonic::MOVQ,      x86OpcodeMap::MODRM, REG::MMX,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x5F

  // 0x70 .. 0x7F (TODO..)
  {Mnemonic::PSHUFW,   x86OpcodeMap::MODRM,  REG::MMX,      REG::I8,        REG::NO_REG,   REG::NO_REG}, // 0x70
  {Mnemonic::OPF_6,    x86OpcodeMap::OPEXT,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x71
  {Mnemonic::OPF_7,    x86OpcodeMap::OPEXT,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x72
  {Mnemonic::OPF_8,    x86OpcodeMap::OPEXT,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x73
  {Mnemonic::PCMPEQB,  x86OpcodeMap::MODRM,  REG::MMX0,     REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0x74
  {Mnemonic::PCMPEQW,  x86OpcodeMap::MODRM,  REG::MMX0,     REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0x75
  {Mnemonic::PCMPEQD,  x86OpcodeMap::MODRM,  REG::MMX0,     REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0x76
  {Mnemonic::EMMS,     x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x77
  {Mnemonic::VMREAD,   x86OpcodeMap::MODRM,  REG::M32,      REG::R32,       REG::NO_REG,   REG::NO_REG}, // 0x78
  {Mnemonic::VMWRITE,  x86OpcodeMap::MODRM,  REG::R32,      REG::M32,       REG::NO_REG,   REG::NO_REG}, // 0x79
  {Mnemonic::DB,       x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x7A
  {Mnemonic::DB,       x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x7B
  {Mnemonic::HADDPD,   x86OpcodeMap::MODRM,  REG::MMX,      REG::XMM,       REG::NO_REG,   REG::NO_REG}, // 0x7C
  {Mnemonic::HSUBPD,   x86OpcodeMap::MODRM,  REG::MMX,      REG::XMM,       REG::NO_REG,   REG::NO_REG}, // 0x7D
  {Mnemonic::MOVD,     x86OpcodeMap::MODRM,  REG::M32,      REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0x7E
  {Mnemonic::MOVQ,     x86OpcodeMap::MODRM,  REG::MMX,      REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0x7F

  // 0x80 .. 0x8F
  {Mnemonic::JO,       x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x80
  {Mnemonic::JNO,      x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x81
  {Mnemonic::JB,       x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x82
  {Mnemonic::JNB,      x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x83
  {Mnemonic::JZ,       x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x84
  {Mnemonic::JNZ,      x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x85
  {Mnemonic::JNA,      x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x86
  {Mnemonic::JA,       x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x87
  {Mnemonic::JS,       x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x88
  {Mnemonic::JNS,      x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x89
  {Mnemonic::JP,       x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x8A
  {Mnemonic::JNP,      x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x8B
  {Mnemonic::JL,       x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x8C
  {Mnemonic::JNL,      x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x8D
  {Mnemonic::JNG,      x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x8E
  {Mnemonic::JG,       x86OpcodeMap::NONE,   REG::REL16_32, REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x8F

  // 0x90 .. 0x9F
  {Mnemonic::SETO,     x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x90
  {Mnemonic::SETNO,    x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x91
  {Mnemonic::SETB,     x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x92
  {Mnemonic::SETNB,    x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x93
  {Mnemonic::SETZ,     x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x94
  {Mnemonic::SETNZ,    x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x95
  {Mnemonic::SETBE,    x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x96
  {Mnemonic::SETNBE,   x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x97
  {Mnemonic::SETS,     x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x98
  {Mnemonic::SETNS,    x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x99
  {Mnemonic::SETP,     x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x9A
  {Mnemonic::SETNP,    x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x9B
  {Mnemonic::SETL,     x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x9C
  {Mnemonic::SETNL,    x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x9D
  {Mnemonic::SETLE,    x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x9E
  {Mnemonic::SETNLE,   x86OpcodeMap::MODRM,  REG::M8,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0x9F

  // 0xA0 .. 0xAF
  {Mnemonic::PUSH,     x86OpcodeMap::NONE,   REG::FS,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xA0
  {Mnemonic::POP,      x86OpcodeMap::NONE,   REG::FS,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xA1
  {Mnemonic::CPUID,    x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xA2
  {Mnemonic::BT,       x86OpcodeMap::MODRM,  REG::M16_32,   REG::R16_32,    REG::NO_REG,   REG::NO_REG}, // 0xA3
  {Mnemonic::SHLD,     x86OpcodeMap::MODRM,  REG::M16_32,   REG::R16_32,    REG::I8,       REG::NO_REG}, // 0xA4
  {Mnemonic::SHLD,     x86OpcodeMap::MODRM,  REG::M16_32,   REG::R16_32,    REG::CL,       REG::NO_REG}, // 0xA5
  {Mnemonic::DB,       x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xA6
  {Mnemonic::DB,       x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xA7
  {Mnemonic::PUSH,     x86OpcodeMap::NONE,   REG::GS,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xA8
  {Mnemonic::POP,      x86OpcodeMap::NONE,   REG::GS,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xA9
  {Mnemonic::RSM,      x86OpcodeMap::NONE,   REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xAA
  {Mnemonic::BTS,      x86OpcodeMap::MODRM,  REG::M16_32,   REG::R16_32,    REG::NO_REG,   REG::NO_REG}, // 0xAB
  {Mnemonic::SHRD,     x86OpcodeMap::MODRM,  REG::M16_32,   REG::R16_32,    REG::I8,       REG::NO_REG}, // 0xAC
  {Mnemonic::SHRD,     x86OpcodeMap::MODRM,  REG::M16_32,   REG::R16_32,    REG::CL,       REG::NO_REG}, // 0xAD
  {Mnemonic::OPF_9,    x86OpcodeMap::OPEXT,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xAE
  {Mnemonic::IMUL,     x86OpcodeMap::MODRM,  REG::M16_32,   REG::R16_32,    REG::NO_REG,   REG::NO_REG}, // 0xAF

  // 0xB0 .. 0xBF
  {Mnemonic::CMPXCHG,  x86OpcodeMap::MODRM,  REG::M8,       REG::R8,        REG::NO_REG,   REG::NO_REG}, // 0xB0
  {Mnemonic::CMPXCHG,  x86OpcodeMap::MODRM,  REG::M16_32,   REG::R16_32,    REG::NO_REG,   REG::NO_REG}, // 0xB1
  {Mnemonic::LSS,      x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0xB2
  {Mnemonic::BTR,      x86OpcodeMap::MODRM,  REG::M16_32,   REG::R16_32,    REG::NO_REG,   REG::NO_REG}, // 0xB3
  {Mnemonic::LFS,      x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0xB4
  {Mnemonic::LGS,      x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0xB5
  {Mnemonic::MOVZX,    x86OpcodeMap::MODRM,  REG::R16_32,   REG::M8,        REG::NO_REG,   REG::NO_REG}, // 0xB6
  {Mnemonic::MOVZX,    x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16,       REG::NO_REG,   REG::NO_REG}, // 0xB7
  {Mnemonic::POPCNT,   x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::NO_REG,   REG::NO_REG}, // 0xB8
  {Mnemonic::UD,       x86OpcodeMap::MODRM,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xB9
  {Mnemonic::OPF_A,    x86OpcodeMap::OPEXT,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xBA
  {Mnemonic::BTC,      x86OpcodeMap::MODRM,  REG::M16_32,   REG::R16_32,    REG::NO_REG,   REG::NO_REG}, // 0xBB
  {Mnemonic::BSF,      x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::I8,       REG::NO_REG}, // 0xBC
  {Mnemonic::BSR,      x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16_32,    REG::CL,       REG::NO_REG}, // 0xBD
  {Mnemonic::MOVSX,    x86OpcodeMap::MODRM,  REG::R16_32,   REG::M8,        REG::NO_REG,   REG::NO_REG}, // 0xBE 
  {Mnemonic::MOVSX,    x86OpcodeMap::MODRM,  REG::R16_32,   REG::M16,       REG::NO_REG,   REG::NO_REG}, // 0xBF

  // 0xC0 .. 0xCF (TODO ...)
  {Mnemonic::XADD,     x86OpcodeMap::MODRM,  REG::M8,       REG::R8,        REG::NO_REG,   REG::NO_REG}, // 0xC0
  {Mnemonic::XADD,     x86OpcodeMap::MODRM,  REG::M16_32,   REG::R16_32,    REG::NO_REG,   REG::NO_REG}, // 0xC1
  {Mnemonic::CMPPS,    x86OpcodeMap::MODRM,  REG::XMM,      REG::I8,        REG::NO_REG,   REG::NO_REG}, // 0xC2
  {Mnemonic::MOVNTI,   x86OpcodeMap::MODRM,  REG::M32,      REG::R32,       REG::NO_REG,   REG::NO_REG}, // 0xC3
  {Mnemonic::PINSRW,   x86OpcodeMap::MODRM,  REG::M16,      REG::I8,        REG::NO_REG,   REG::NO_REG}, // 0xC4
  {Mnemonic::PEXTRW,   x86OpcodeMap::MODRM,  REG::R32,      REG::MMX,       REG::I8,       REG::NO_REG}, // 0xC5
  {Mnemonic::SHUFPS,   x86OpcodeMap::MODRM,  REG::XMM,      REG::I8,        REG::NO_REG,   REG::NO_REG}, // 0xC6
  {Mnemonic::OPF_B,    x86OpcodeMap::OPEXT,  REG::NO_REG,   REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xC7
  {Mnemonic::BSWAP,    x86OpcodeMap::NONE,   REG::EAX,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xC8
  {Mnemonic::BSWAP,    x86OpcodeMap::NONE,   REG::ECX,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xC9
  {Mnemonic::BSWAP,    x86OpcodeMap::NONE,   REG::EDX,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xCA
  {Mnemonic::BSWAP,    x86OpcodeMap::NONE,   REG::EBX,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xCB
  {Mnemonic::BSWAP,    x86OpcodeMap::NONE,   REG::ESP,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xCC
  {Mnemonic::BSWAP,    x86OpcodeMap::NONE,   REG::EBP,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xCD
  {Mnemonic::BSWAP,    x86OpcodeMap::NONE,   REG::ESI,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xCE
  {Mnemonic::BSWAP,    x86OpcodeMap::NONE,   REG::EDI,      REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xCF

  // 0xD0 .. 0xDF (TODO)
  {Mnemonic::ADDSUBPD, x86OpcodeMap::MODRM,  REG::MMX,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xD0
  {Mnemonic::PSRLW,    x86OpcodeMap::MODRM,  REG::MMX,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xD1
  {Mnemonic::PSRLD,    x86OpcodeMap::MODRM,  REG::MMX,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xD2
  {Mnemonic::PSRLQ,    x86OpcodeMap::MODRM,  REG::MMX,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xD3
  {Mnemonic::PADDQ,    x86OpcodeMap::MODRM,  REG::MMX,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xD4
  {Mnemonic::PMULLW,   x86OpcodeMap::MODRM,  REG::MMX,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xD5
  {Mnemonic::MOVQ,     x86OpcodeMap::MODRM,  REG::M32,       REG::XMM,       REG::NO_REG,   REG::NO_REG}, // 0xD6
  {Mnemonic::PMOVMSKB, x86OpcodeMap::MODRM,  REG::R32,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xD7
  {Mnemonic::PSUBUSB,  x86OpcodeMap::MODRM,  REG::MMX,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xD8
  {Mnemonic::PSUBUSW,  x86OpcodeMap::MODRM,  REG::MMX,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xD9
  {Mnemonic::PMINUB,   x86OpcodeMap::MODRM,  REG::MMX,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xDA
  {Mnemonic::PAND,     x86OpcodeMap::MODRM,  REG::MMX,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xDB
  {Mnemonic::PADDUSB,  x86OpcodeMap::MODRM,  REG::MMX,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xDC
  {Mnemonic::PADDUSW,  x86OpcodeMap::MODRM,  REG::MMX,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xDD
  {Mnemonic::PMAXUB,   x86OpcodeMap::MODRM,  REG::MMX,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xDE
  {Mnemonic::PANDN,    x86OpcodeMap::MODRM,  REG::MMX,       REG::NO_REG,    REG::NO_REG,   REG::NO_REG}, // 0xDF

  // 0xE0 .. 0xEF (TODO ...)
  {Mnemonic::PAVGB,    x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xE0
  {Mnemonic::PSRAW,    x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xE1
  {Mnemonic::PSRAD,    x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xE2
  {Mnemonic::PAVGW,    x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xE3
  {Mnemonic::PMULHUW,  x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xE4
  {Mnemonic::PMULHW,   x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xE5
  {Mnemonic::CVTPD2DQ, x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xE6
  {Mnemonic::MOVNTQ,   x86OpcodeMap::MODRM,  REG::M64,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xE7
  {Mnemonic::PSUBSB,   x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xE8
  {Mnemonic::PSUBSW,   x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xE9
  {Mnemonic::PMINSW,   x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xEA
  {Mnemonic::POR,      x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xEB
  {Mnemonic::PADDSB,   x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xEC
  {Mnemonic::PADDSW,   x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xED
  {Mnemonic::PMAXSW,   x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xEE
  {Mnemonic::PXOR,     x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xEF

  // 0xF0 .. 0xFF (TODO ...)
  {Mnemonic::LDDQU,    x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xF0
  {Mnemonic::PSLLW,    x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xF1
  {Mnemonic::PSLLD,    x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xF2
  {Mnemonic::PSLLQ,    x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xF3
  {Mnemonic::PMULUDQ,  x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xF4
  {Mnemonic::PMADDWD,  x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xF5
  {Mnemonic::PSADBW,   x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xF6
  {Mnemonic::MASKMOVQ, x86OpcodeMap::MODRM,  REG::M64,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xF7
  {Mnemonic::PSUBB,    x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xF8
  {Mnemonic::PSUBW,    x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xF9
  {Mnemonic::PSUBD,    x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xFA
  {Mnemonic::PSUBQ,    x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xFB
  {Mnemonic::PADDB,    x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xFC
  {Mnemonic::PADDW,    x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xFD
  {Mnemonic::PADDD,    x86OpcodeMap::MODRM,  REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xFE
  {Mnemonic::DB,       x86OpcodeMap::NONE,   REG::MMX,       REG::MMX,       REG::NO_REG,   REG::NO_REG}, // 0xFF
};

// -------------------------------------------------------------------------------
// Mnemonic | S. Opcode | Ext. | Opcode 1 | Opcode 2 | Opcode 3 | Opcode 4 
// -------------------------------------------------------------------------------
const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMap80[] = // 0x80 + 0x82
{
  {Mnemonic::ADD,    0x00,  0,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::OR,     0x00,  1,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::ADC,    0x00,  2,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SBB,    0x00,  3,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::AND,    0x00,  4,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SUB,    0x00,  5,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::XOR,    0x00,  6,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::CMP,    0x00,  7,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMap81[] = // 0x81
{
  {Mnemonic::ADD,    0x00,  0,   REG::M16_32,   REG::I16_32,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::OR,     0x00,  1,   REG::M16_32,   REG::I16_32,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::ADC,    0x00,  2,   REG::M16_32,   REG::I16_32,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SBB,    0x00,  3,   REG::M16_32,   REG::I16_32,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::AND,    0x00,  4,   REG::M16_32,   REG::I16_32,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SUB,    0x00,  5,   REG::M16_32,   REG::I16_32,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::XOR,    0x00,  6,   REG::M16_32,   REG::I16_32,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::CMP,    0x00,  7,   REG::M16_32,   REG::I16_32,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMap83[] = // 0x83
{
  {Mnemonic::ADD,    0x00,  0,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::OR,     0x00,  1,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::ADC,    0x00,  2,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SBB,    0x00,  3,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::AND,    0x00,  4,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SUB,    0x00,  5,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::XOR,    0x00,  6,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::CMP,    0x00,  7,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMapC0[] = // 0xC0
{
  {Mnemonic::ROL,    0x00,  0,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::ROR,    0x00,  1,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::RCL,    0x00,  2,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::RCR,    0x00,  3,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHL,    0x00,  4,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHR,    0x00,  5,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHL,    0x00,  6,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SAR,    0x00,  7,   REG::M8,       REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMapC1[] = // 0xC1
{
  {Mnemonic::ROL,    0x00,  0,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::ROR,    0x00,  1,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::RCL,    0x00,  2,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::RCR,    0x00,  3,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHL,    0x00,  4,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHR,    0x00,  5,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHL,    0x00,  6,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SAR,    0x00,  7,   REG::M16_32,   REG::I8,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMapD0[] = // 0xD0
{
  {Mnemonic::ROL,    0x00,  0,   REG::M8,       REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::ROR,    0x00,  1,   REG::M8,       REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::RCL,    0x00,  2,   REG::M8,       REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::RCR,    0x00,  3,   REG::M8,       REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHL,    0x00,  4,   REG::M8,       REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHR,    0x00,  5,   REG::M8,       REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHL,    0x00,  6,   REG::M8,       REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SAR,    0x00,  7,   REG::M8,       REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMapD1[] = // 0xD1
{
  {Mnemonic::ROL,    0x00,  0,   REG::M16_32,   REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::ROR,    0x00,  1,   REG::M16_32,   REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::RCL,    0x00,  2,   REG::M16_32,   REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::RCR,    0x00,  3,   REG::M16_32,   REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHL,    0x00,  4,   REG::M16_32,   REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHR,    0x00,  5,   REG::M16_32,   REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHL,    0x00,  6,   REG::M16_32,   REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SAR,    0x00,  7,   REG::M16_32,   REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMapD2[] = // 0xD2
{
  {Mnemonic::ROL,    0x00,  0,   REG::M8,       REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::ROR,    0x00,  1,   REG::M8,       REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::RCL,    0x00,  2,   REG::M8,       REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::RCR,    0x00,  3,   REG::M8,       REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHL,    0x00,  4,   REG::M8,       REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHR,    0x00,  5,   REG::M8,       REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHL,    0x00,  6,   REG::M8,       REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SAR,    0x00,  7,   REG::M8,       REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMapD3[] = // 0xD3
{
  {Mnemonic::ROL,    0x00,  0,   REG::M16_32,   REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::ROR,    0x00,  1,   REG::M16_32,   REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::RCL,    0x00,  2,   REG::M16_32,   REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::RCR,    0x00,  3,   REG::M16_32,   REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHL,    0x00,  4,   REG::M16_32,   REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHR,    0x00,  5,   REG::M16_32,   REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SHL,    0x00,  6,   REG::M16_32,   REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::SAR,    0x00,  7,   REG::M16_32,   REG::CL,         REG::NO_REG,         REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

// The F* Opcodes are weird, I'm just going to hard code handling in the ModRM class...
// If a reg can have either STi or FP, place FP instead to allow the FSM to decide.
const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMap4[] = // 0xD8
{
  {Mnemonic::FADD,   0x00,  0,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::FMUL,   0x00,  1,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::FCOM,   0x00,  2,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::FCOMP,  0x00,  3,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::FSUB,   0x00,  4,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::FSUBR,  0x00,  5,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::FDIV,   0x00,  6,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::FDIVR,  0x00,  7,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,         REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMap5[] = // 0xD9
{
  {Mnemonic::FLD,     0x00,  0,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FXCH,    0x00,  1,   REG::STi,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FST,     0x00,  2,   REG::STi,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FNOP,    0xD0,  2,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FSTP,    0x00,  3,   REG::STi,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FCHS,    0xE0,  4,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FABS,    0xE1,  4,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FTST,    0xE4,  4,   REG::STi,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FXAM,    0xE5,  4,   REG::STi,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FLDENV,  0x00,  4,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FLD1,    0xE8,  5,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FLDL2T,  0xE9,  5,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FLDL2E,  0xEA,  5,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FLDPI,   0xEB,  5,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FLDLG2,  0xEC,  5,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FLDLN2,  0xED,  5,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FLDZ,    0xEE,  5,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FLDCW,   0x00,  5,   REG::M16,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::F2XM1,   0xF0,  6,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FYL2X,   0xF1,  6,   REG::STi,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FPTAN,   0xF2,  6,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FPATAN,  0xF3,  6,   REG::STi,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FXTRACT, 0xF4,  6,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FPREM1,  0xF5,  6,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FDECSTP, 0xF6,  6,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FINCSTP, 0xF7,  6,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FPREM,   0xF8,  7,   REG::ST1,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FYL2XP1, 0xF9,  7,   REG::STi,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FSQRT,   0xFA,  7,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FSINCOS, 0xFB,  7,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FRNDINT, 0xFC,  7,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FSCALE,  0xFD,  7,   REG::ST1,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FSIN,    0xFE,  7,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FCOS,    0xFF,  7,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FNSTCW,  0x00,  7,   REG::M16,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMap6[] = // 0xDA
{
  {Mnemonic::FCMOVB,  0x00,  0,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FCMOVE,  0x00,  1,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FCMOVBE, 0x00,  2,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FCMOVU,  0x00,  3,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FISUB,   0x00,  4,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FISUBR,  0x00,  5,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FIDIV,   0x00,  6,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FIDIVR,  0x00,  7,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMap7[] = // 0xDB
{
  {Mnemonic::FCMOVNB, 0x00,  0,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FCMOVNE, 0x00,  1,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FCMOVNBE,0x00,  2,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FCMOVNU, 0x00,  3,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FNENI,   0xE0,  4,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FNDISI,  0xE1,  4,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FNCLEX,  0xE2,  4,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FINIT,   0xE3,  4,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::NOP,     0xE4,  4,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FUCOMI,  0x00,  5,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FCOMI,   0x00,  6,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FSTP,    0x00,  7,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMap8[] = // 0xDC
{
  {Mnemonic::FADD,    0x00,  0,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FMUL,    0x00,  1,   REG::M64_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FCOM,    0x00,  2,   REG::M64_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FCOMP,   0x00,  3,   REG::M64_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FSUB,    0x00,  4,   REG::M64_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FSUBR,   0x00,  5,   REG::M64_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FDIV,    0x00,  6,   REG::M64_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FDIVR,   0x00,  7,   REG::M64_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMap9[] = // 0xDD
{
  {Mnemonic::FFREE,   0x00,  0,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FXCH4,   0x00,  1,   REG::M64_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FST,     0x00,  2,   REG::M64_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FSTP,    0x00,  3,   REG::M64_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FUCOM,   0x00,  4,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FUCOMP,  0x00,  5,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FSAVE,   0x00,  6,   REG::M32_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FSTSW,   0x00,  7,   REG::M16,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMapA[] = // 0xDE
{
  {Mnemonic::FADDP,   0x00,  0,   REG::M16_INT,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FMULP,   0x00,  1,   REG::M16_INT,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FCOMP5,  0x00,  2,   REG::M16_INT,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FCOMPP,  0x00,  3,   REG::M16_INT,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FSUBRP,  0x00,  4,   REG::M16_INT,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FSUBP,   0x00,  5,   REG::M16_INT,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FDIVRP,  0x00,  6,   REG::M16_INT,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FDIVP,   0x00,  7,   REG::M16_INT,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMapB[] = // 0xDF
{
  {Mnemonic::FFREEP,  0x00,  0,   REG::M16_INT,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FXCH7,   0x00,  1,   REG::M16_INT,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FSTP8,   0x00,  2,   REG::M16_INT,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FSTP9,   0x00,  3,   REG::M16_INT,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FBLD,    0x00,  4,   REG::M80_DEC,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FUCOMIP, 0x00,  5,   REG::M64_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FCOMIP,  0x00,  6,   REG::M80_DEC,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FISTP,   0x00,  7,   REG::M64_FP,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMapC[] = // 0xF6
{
  {Mnemonic::TEST,    0x00,  0,   REG::M8,        REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::TEST,    0x00,  1,   REG::M8,        REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::NOT,     0x00,  2,   REG::M8,        REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::NEG,     0x00,  3,   REG::M8,        REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MUL,     0x00,  4,   REG::M8,        REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::IMUL,    0x00,  5,   REG::M8,        REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::DIV,     0x00,  6,   REG::M8,        REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::IDIV,    0x00,  7,   REG::M8,        REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMapD[] = // 0xF7
{
  {Mnemonic::TEST,    0x00,  0,   REG::M16_32,    REG::I16_32,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::TEST,    0x00,  1,   REG::M16_32,    REG::I16_32,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::NOT,     0x00,  2,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::NEG,     0x00,  3,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MUL,     0x00,  4,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::IMUL,    0x00,  5,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::DIV,     0x00,  6,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::IDIV,    0x00,  7,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMapE[] = // 0xFE
{
  {Mnemonic::INC,     0x00,  0,   REG::M8,        REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::DEC,     0x00,  1,   REG::M8,        REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE}, // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::ExtensionMapF[] = // 0xFF
{
  {Mnemonic::INC,     0x00,  0,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::DEC,     0x00,  1,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::CALL,    0x00,  2,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::CALLF,   0x00,  3,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::JMP,     0x00,  4,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::JMPF,    0x00,  5,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PUSH,    0x00,  6,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::Extension0F_0[] = // 0x0F 0x00
{
  {Mnemonic::SLDT,    0x00,  0,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::STR,     0x00,  1,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::LLDT,    0x00,  2,   REG::M16,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::LTR,     0x00,  3,   REG::M16,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::VERR,    0x00,  4,   REG::M16,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::VERW,    0x00,  5,   REG::M16,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::Extension0F_1[] = // 0x0F 0x01
{
  {Mnemonic::VMCALL,  0xC1,  0,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::VMLAUNCH,0xC2,  0,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::VMRESUME,0xC3,  0,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::VMXOFF,  0xC4,  0,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::SGDT,    0x00,  0,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MONITOR, 0xC8,  1,   REG::M8,        REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MWAIT,   0xC9,  1,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::SIDT,    0x00,  1,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::XGETBV,  0xD0,  2,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::XSETBV,  0xD1,  2,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::LGDT,    0x00,  2,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::LIDT,    0x00,  3,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::SMSW,    0x00,  4,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::LMSW,    0x00,  6,   REG::M16,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::RDTSCP,  0xF9,  7,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::INVLPG,  0x00,  7,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::Extension0F_2[] = // 0x0F 0x18
{
  {Mnemonic::PREFETCHNTA,0x00,  0,   REG::M8,        REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PREFETCHT0, 0x00,  1,   REG::M8,        REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PREFETCHT1, 0x00,  2,   REG::M8,        REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PREFETCHT2, 0x00,  3,   REG::M8,        REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  4,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  5,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  6,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  7,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::Extension0F_3[] = // 0x0F 0x1F
{
  {Mnemonic::NOP,        0x00,  0,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  1,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  2,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  3,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  4,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  5,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  6,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  7,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::Extension0F_4[] = // 0x0F 0x38 (TODO.... ALSO MM/M64 and XMM/M128)
{
  {Mnemonic::PMADDUBSW,  0x04,  0,   REG::M64_128,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PHADDSW,    0x03,  0,   REG::M64_128,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PHADDD,     0x02,  0,   REG::M64_128,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PHADDW,     0x01,  0,   REG::M64_128,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PSHUFB,     0x00,  0,   REG::M64_128,   REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  1,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  2,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  3,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  4,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  5,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  6,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::HINT_NOP,   0x00,  7,   REG::M16_32,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::Extension0F_5[] = // 0x0F 0x3A (TODO.... ALSO MM/M64 and XMM/M128)
{
  {Mnemonic::ROUNDPS,    0x08,  0,   REG::XMM,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::ROUNDPD,    0x09,  0,   REG::XMM,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::ROUNDSS,    0x0A,  0,   REG::XMM,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::ROUNDSD,    0x0B,  0,   REG::XMM,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::BLENDPS,    0x0C,  0,   REG::XMM,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::BLENDPD,    0x0D,  0,   REG::XMM,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PBLENDW,    0x0E,  0,   REG::XMM,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PALIGNR,    0x0F,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PEXTRB,     0x14,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PEXTRW,     0x15,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PEXTRD,     0x16,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PINSRB,     0x0F,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::EXTRACTPS,  0x17,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PINSRB,     0x20,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::INSERTPS,   0x21,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PINSRD,     0x22,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::DPPS,       0x40,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::DPPD,       0x41,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MPSADBW,    0x42,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PCMPESTRM,  0x60,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PCMPESTRI,  0x61,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PCMPISTRM,  0x62,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PCMPISTRI,  0x63,  0,   REG::XMM,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::Extension0F_6[] = // 0x0F 0x71
{
  {Mnemonic::PSRLW,      0x00,  2,   REG::MMX,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PSRAW,      0x00,  4,   REG::MMX,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PSLLW,      0x00,  6,   REG::MMX,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::Extension0F_7[] = // 0x0F 0x72
{
  {Mnemonic::PSRLD,      0x00,  2,   REG::MMX,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PSRAD,      0x00,  4,   REG::MMX,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PSLLD,      0x00,  6,   REG::MMX,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::Extension0F_8[] = // 0x0F 0x73
{
  {Mnemonic::PSRLQ,      0x00,  2,   REG::MMX,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PSRLDQ,     0x00,  4,   REG::MMX,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PSLLQ,      0x00,  6,   REG::MMX,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::PSLLDQ,     0x00,  7,   REG::MMX,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::Extension0F_9[] = // 0x0F 0xAE (TODO.)
{
  {Mnemonic::FXSAVE,     0x00,  0,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::FXRSTOR,    0x00,  1,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::LDMXCSR,    0x00,  2,   REG::M32,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::STMXCSR,    0x00,  3,   REG::M32,       REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::LFENCE,     0x00,  4,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::XRSTOR,     0x00,  5,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MFENCE,     0x00,  6,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::SFENCE,     0x00,  7,   REG::NO_REG,    REG::NO_REG,     REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::Extension0F_A[] = // 0x0F 0xBA
{
  {Mnemonic::BT,         0x00,  4,   REG::M16_32,    REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::BTS,        0x00,  5,   REG::M16_32,    REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::BTC,        0x00,  6,   REG::M16_32,    REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::BTC,        0x00,  7,   REG::M16_32,    REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable x86OpcodeMap::Extension0F_B[] = // 0x0F 0xC7
{
  {Mnemonic::CMPXCHG8B,  0x00,  1,   REG::M32,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::VMPTRLD,    0x00,  6,   REG::M32,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::VMPTRST,    0x00,  7,   REG::M32,       REG::I8,         REG::NO_REG,       REG::NO_REG},
  {Mnemonic::MAX_OPCODE} // Must be last entry
};

const x86OpcodeMap::ExtensionTable* x86OpcodeMap::ExtensionTables[] =
{
  ExtensionMap80,
  ExtensionMap81,
  ExtensionMap83,
  ExtensionMapC0,
  ExtensionMapC1,
  ExtensionMapD0,
  ExtensionMapD1,
  ExtensionMapD2,
  ExtensionMapD3,
  ExtensionMap4,
  ExtensionMap5,
  ExtensionMap6,
  ExtensionMap7,
  ExtensionMap8,
  ExtensionMap9,
  ExtensionMapA,
  ExtensionMapB,
  ExtensionMapC,
  ExtensionMapD,
  ExtensionMapE,
  ExtensionMapF,
  Extension0F_0,
  Extension0F_1,
  Extension0F_2,
  Extension0F_3,
  Extension0F_4,
  Extension0F_5,
  Extension0F_6,
  Extension0F_7,
  Extension0F_8,
  Extension0F_9,
  Extension0F_A,
  Extension0F_B
};
