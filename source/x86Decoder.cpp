#include "x86Decoder.h"
#include "x86Instruction.h"

// --------------------------------------------------------------------------------------
// Function:  Disassemble
// Parameters:
//   (O) disassembly     - output disassembly
//   (I) maxInstructions - maximum instructions to disassemble
// Special Notes: None
// --------------------------------------------------------------------------------------
void x86Decoder::Disassemble(std::vector<DEInstruction>& disassembly,
                             size_t maxInstructions) const
{
  disassembly.clear();

  size_t offset = 0;
  bool success = false;

  size_t maxInst = (0 == maxInstructions ? 0xFFFFFFFF : maxInstructions);
  for (size_t i = 0; i < maxInst; ++i)
  {
    // Exit if we exceed buffer limit for first byte. All other checks
    // happen within x86Instruction via Exception handling.
    if (Length <= offset)
    {
      break;    
    }

    DEInstruction instruction;
    instruction.Address = RelativeAddress + offset;

    // Build the disassembly.
    x86Instruction inst(Buffer, 
                        offset, 
                        Length, 
                        static_cast<uint32_t>(RelativeAddress), 
                        success);
    instruction.Data = inst.GetData();

    if (false == success)
    {
      if (i < maxInst)
      {
        instruction.Instruction = "Disassemble error";
        disassembly.emplace_back(instruction);
        break;
      }
    }

    instruction.Instruction = inst.BuildInstruction();
    disassembly.emplace_back(instruction);
  }
}

// --------------------------------------------------------------------------------------
// Function:  x86Decoder
// Parameters:
//   (I) buffer - Pointer to data
//   (I) length - Length of data
//   (I) relativeAddr - The base address of data the buffer contains
// Special Notes: None
// --------------------------------------------------------------------------------------
x86Decoder::x86Decoder(char* buffer, size_t length, uintptr_t relativeAddr) :
  Buffer(buffer),
  Length(length),
  RelativeAddress(relativeAddr),
  Offset(0)
{

}

// --------------------------------------------------------------------------------------
// Function:  ~x86Decoder
// Parameters: None
//
// Special Notes: None
// --------------------------------------------------------------------------------------
x86Decoder::~x86Decoder()
{

}