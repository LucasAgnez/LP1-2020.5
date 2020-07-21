#if !defined(NEGOCIOEXCEPTION_H)
#define NEGOCIOEXCEPTION_H

#include <string>

class NegocioException
{
private:
  std::string cause;
  int line;
public:
  NegocioException(std::string cause, int line);
  NegocioException(std::string cause);

  std::string what();
};

#endif // NEGOCIOEXCEPTION_H
