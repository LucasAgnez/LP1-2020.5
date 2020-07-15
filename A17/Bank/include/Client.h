#ifndef W5_CLIENT_H
#define W5_CLIENT_H

#include<iostream>
#include<string>

class Client{
  public:
  Client();
  Client(std::string name, std::string cpf);

  std::string cpf;
  std::string name;
  static int clients_number;
};

#endif
