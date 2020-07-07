#include"Account.h"

int main(int argc, char* argv[]){
  Account a;
  a.balance = 1000.48;
  a.draw(500);
  a.titular.cpf = "106.781.494-39";
  a.titular.name = "Lucas Agnez Lima";
  a.agency.name = "BB";
  a.agency.number = "1234-5";
  std::cout << a.titular.cpf << " - " << a.titular.name << std::endl;
  std::cout << a.agency.name << " - " << a.agency.number << std::endl;
}
