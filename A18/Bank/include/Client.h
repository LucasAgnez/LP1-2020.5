
#if !defined(CLIENT_H)
#define CLIENT_H

#include <string>

class Client
{
protected:
  std::string name;

public:
  Client();
  Client(std::string name);

  std::string getName() {
    return this->name;
  }
  void setName(std::string n) {
    this->name = n;
  }
};

#endif
