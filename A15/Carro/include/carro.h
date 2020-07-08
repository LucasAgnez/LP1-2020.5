#ifndef W5_CARRO_H
#define W5_CARRO_H

#include <string>
#include "motor.h"


class Carro{

  public:
    Carro(std::string tipo, std::string placa, int numPortas, std::string cor);
    Carro();

    std::string tipo;
    std::string placa;
    int numPortas;
    std::string cor;
    int velocidade;
    Motor motor;

    static int numero_carros;

    void acelera(int velocidade);
    void freia(int velocidade);
    void ligaCarro();
};

#endif
