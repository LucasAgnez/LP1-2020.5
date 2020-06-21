#include<iostream>
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
		std::cout << "Insira sua Mensagem: " << std::endl;
		std::getline(std::cin, mensagem);
		std::cout << mensagem << std::endl;
		return 0;
	}
	if(strcmp(argv[1], "add")){
		std::cout << "Uso: " << argv[0] << " add <'mensagem'>" << std::endl;
		return 1;
	}
	std::cout << argv[2] << std::endl;
	return 0;
}
