#ifndef W5N_ACCOUNT_H
#define W5N_ACCOUNT_H

#include <string>
#include <iostream>
#include "Client.h"
#include "Agency.h"


class Account{
  public:
  Client titular;
  Agency agency;
  double balance;
  Account();
  Account(Client titular, Agency agency, double balance);
  static int accounts_number;

  void deposit(double amount);
  void transfer(double amount, Account &a);
  void draw(double amout);
};

#endif
