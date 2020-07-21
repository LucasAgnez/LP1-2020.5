#include "NegocioException.h"

NegocioException::NegocioException(std::string c, int l) : cause(c), line(l)
{

}

NegocioException::NegocioException(std::string c) : cause(c), line(0)
{
}

std::string NegocioException::what() {
  std::string msg;
  if(!cause.empty() && line != 0) {
    msg = "Line " + std::to_string(line) + ": " + cause;
  } else if(line == 0) {
    msg = cause;
  }
  
  return msg;
}