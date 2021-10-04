#pragma once
#include <stdint.h>
#include <string>
#include <vector>

// This is the class used to decode data into x86 assembly.
class x86Decoder
{
public:

  struct DEInstruction
  {
    uintptr_t Address;
    std::vector<uint8_t> Data;
    std::string Instruction;
  };

  void Disassemble(std::vector<DEInstruction>& disassembly, 
                   size_t maxInstructions) const;
  x86Decoder(char* buffer, size_t length, uintptr_t relativeAddr);
  ~x86Decoder();

private:
  
  char* Buffer;
  size_t Length;
  uintptr_t RelativeAddress;
  size_t Offset;
};