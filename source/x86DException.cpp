#include "x86DException.h"
#include <iostream>
#include <string>


// --------------------------------------------------------------------------------------
// Function: PrintException
// Parameters:
//   (I) exception - description of error
// Notes:  None
// --------------------------------------------------------------------------------------
void x86DException::PrintException() const
{
  std::string exceptionType;
  switch (Status)
  {
    case BUFFER_OVERFLOW:
      exceptionType = "BUFFER OVERFLOW";
      break;
    case INVALID_OPCODE_MAP:
      exceptionType = "OPCODE MAP ERROR";
      break;
    case INVALID_REG_MAP:
      exceptionType = "REGISTER MAP ERROR";
      break;
  }

  std::cout << "Exception: " << exceptionType.c_str() << " at " 
            << std::hex << Address << std::dec << std::endl;
}

// --------------------------------------------------------------------------------------
// Function: x86DException
// Parameters: None
// Notes:  None
// --------------------------------------------------------------------------------------
x86DException::x86DException(ExceptionTypeEnum type, uintptr_t addr, bool fatal) :
  Status(type),
  Address(addr),
  Fatal(fatal)
{

}

// --------------------------------------------------------------------------------------
// Function: ~x86DException
// Parameters: None
// Notes:  None
// --------------------------------------------------------------------------------------
x86DException::~x86DException()
{

}