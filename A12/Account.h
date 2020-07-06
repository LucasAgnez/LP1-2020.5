#ifndef W5N_ACCOUNT_H
#define W5N_ACCOUNT_H

#include<string>
#include<iostream>

class Account{
  public:
  int Number;
  std::string owner;
  double balance;

  void deposit(double amount);
  void transfer(double amount, Account &a);
  void draw(double amout);
};

#endif
