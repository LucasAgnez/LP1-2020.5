#include"Account.h"

int main(int argc, char* argv[]){

  Agency agency("1234-5", "BB");

  Client C1("Lucas Agnez Lima", "106.781.494-39" );
  Client C2;
  C2.name = ("Rogerinho Cleiton Rasta");
  C2.cpf = ("123.456.789-10");

  Account a(C1, agency, 1000.48);
  Account b(C2, agency, 2345.67);
  Account c;

  a.draw(500);
  b.transfer(100, a);

  std::cout << a.titular.cpf << " - " << a.titular.name << std::endl;
  std::cout << a.agency.name << " - " << a.agency.number << std::endl;
  std::cout << a.balance << std::endl;

  std::cout << b.titular.cpf << " - " << b.titular.name << std::endl;
  std::cout << b.agency.name << " - " << b.agency.number << std::endl;
  std::cout << b.balance << std::endl;

  std::cout << c.titular.cpf << " - " << c.titular.name << std::endl;
  std::cout << c.agency.name << " - " << c.agency.number << std::endl;
  std::cout << c.balance << std::endl;

  std::cout << "Number of Accounts: " << Account::accounts_number << std::endl;
  std::cout << "Number of Clients: " << Client::clients_number << std::endl;

}
