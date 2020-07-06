#include"Account.h"

void Account::draw(double amount){
  this->balance -= amount;

}
void Account::deposit(double amount){
  this->balance += amount;
}

void Account::transfer(double amount, Account &a){
  this->balance -= amount;
  a.deposit(amount);
}
