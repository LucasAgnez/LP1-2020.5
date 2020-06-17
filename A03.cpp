#include<iostream>
#include<fstream>
#include<string.h>

int main(int argc, char *argv[]){
	if(argc == 1){
		std::cout << "Uso: " << argv[0] << " add <'mensagem'>" << std::endl;
		return 1;
	}
	if (argc == 2){
		if(strcmp(argv[1], "add")){
			std::cout << "Uso: " << argv[0] << " add <'mensagem'>" << std::endl;
			return 1;
		}
		std::string mensagem;
		std::ofstream arquivo_saida("arquivo", std::ios::out);
		std::cout << "Insira sua Mensagem: " << std::endl;
		std::getline(std::cin, mensagem);
		arquivo_saida << mensagem;
		arquivo_saida.close();
		std::cout << "Arquivo Salvo Com Sucesso" << std::endl;
		return 0;
	}
	if(strcmp(argv[1], "add")){
		std::cout << "Uso: " << argv[0] << " add <'mensagem'>" << std::endl;
		return 1;
	}
	std::ofstream arquivo_saida("arquivo", std::ios::out);
	arquivo_saida << argv[2];
	arquivo_saida.close();
	std::cout << "Arquivo Salvo Com Sucesso" << std::endl;
	return 0;
}
