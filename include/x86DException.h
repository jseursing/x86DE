#pragma once
#include <exception>
#include <stdint.h>

// This class represents a raised exception made by the disassembler.
class x86DException : public std::exception
{
public:
  enum ExceptionTypeEnum
  {
    BUFFER_OVERFLOW,
    INVALID_OPCODE_MAP,
    INVALID_REG_MAP
  };
  
  void PrintException() const;
  x86DException(ExceptionTypeEnum type, uintptr_t addr, bool fatal);
  ~x86DException();

  bool Fatal;
  uintptr_t Address;
  ExceptionTypeEnum Status;
};