#include"Account.h"

int main(int argc, char* argv[]){
  Account a;
  a.owner = "Lucas Agnez Lima";
  a.Number = 1556;
  a.balance = 20;
  std::cout << "Balance: " << a.balance << std::endl;
  a.draw(10);
  std::cout << "Balance: " <<  a.balance << std::endl;
  a.deposit(200);
  std::cout << "Balance: " << a.balance << std::endl;
  Account b;
  b.balance = 0;
  std::cout << "Balance B: " << b.balance << std::endl;
  a.transfer(104.23, b);
  std::cout << "Balance A: " << a.balance << std::endl;
  std::cout << "Balance B: " << b.balance << std::endl;
}
