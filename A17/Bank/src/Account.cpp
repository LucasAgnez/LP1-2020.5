#include"Account.h"

int Account::accounts_number;

Account::Account() : titular(), agency(), balance(0)
{
  this->accounts_number += 1;
}

Account::Account(Client titular, Agency agency, double balance): titular(titular), agency(agency), balance(balance)
{
  this->accounts_number += 1;
}

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
