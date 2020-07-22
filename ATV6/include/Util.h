#ifndef W5_APP_H
#define W5_APP_H

#include "Util.h"

#include <iostream>
#include <string>
#include <sstream>

void menu_restaurante();

void menu_supermercado();

double set_double(std::string prec);

int set_int(std::string cod);

int set_int2(std::string cod);

void limpar_registro(int n, std::string tipo);

#endif
