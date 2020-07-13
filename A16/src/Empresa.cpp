#include "Empresa.h"


Empresa::Empresa()
{
}

Empresa::Empresa(std::string nome, std::string cnpj)
  : nome(nome), cnpj(cnpj)
{
}
std::string Empresa::get_nome() {
 return nome;
}

void Empresa::set_nome(std::string n) {
  nome = n;
}

std::string Empresa::get_cnpj() {
  return cnpj;
}

void Empresa::set_cnpj(std::string c) {
  cnpj = c;
}

std::vector<Funcionario>& Empresa::get_funcionarios() {
    return funcionarios;
}

void Empresa::set_funcionarios(std::vector<Funcionario> f) {
  funcionarios = f;
}

void Empresa::set_n_funcionarios(int n){
  n_funcionarios = n;
}

void Empresa::aumenta_salario(std::string departamento, double aumento) {
  for (int i = 0; i < n_funcionarios; i++) {
    if (funcionarios[i].get_departamento() == departamento) {
      funcionarios[i].set_salario(funcionarios[i].get_salario()*aumento);
    }
  }
}


void Empresa::listar_funcionarios() {
  for (int i = 0; i < n_funcionarios; i++) {
    std::cout << std::endl;
    std::cout << "Nome: " << funcionarios[i].get_nome() << std::endl;
    std::cout << "Departamento: " << funcionarios[i].get_departamento() << std::endl;
    std::cout << "Salário: " << funcionarios[i].get_salario() << std::endl;
    std::cout << "Data de Admissão: " << funcionarios[i].get_data_admissao() << std::endl;
    std::cout << std::endl;
  }
}
