#include "carro.h"

int Carro::numero_carros;

Carro::Carro(std::string tipo, std::string placa, int numPortas, std::string cor)
  : tipo(tipo), placa(placa), numPortas(numPortas), cor(cor)
{
    this->numero_carros += 1;
}

Carro::Carro() : cor ("Branco")
{
    this->numero_carros += 1;
}

void Carro::acelera(int velocidade){
    this->velocidade += velocidade;
}

void Carro::freia(int velocidade){
    this->velocidade -= velocidade;
}

void Carro::ligaCarro(){
    motor.partida();
}
