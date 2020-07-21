#ifndef W5_RESTAURANTE_H
#define W5_RESTAURANTE_H

#include "Estabelecimento.h"

class Restaurante : public Estabelecimento
{
public:
  Restaurante();
  Restaurante(std::string menuFilename);
  ~Restaurante();

  // Carregar o arquivo menu.csv
  void load();
  void listar();
  int venda(int codigo);
};

#endif // W5_RESTAURANTE_H
