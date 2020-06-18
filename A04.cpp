#include<iostream>
#include<fstream>
#include<string.h>

int add_by_arg(char arg[]){
	std::ofstream note("diario.txt", std::ios::app);
	if(!note.is_open()){
	  std::cerr << "E: Arquivo Nao Existente ou Inacessivel" << std::endl;
	  return 1;
  }
	note << arg;
	note << std::endl;
	note.close();
	std::cout << "Arquivo Salvo Com Sucesso" << std::endl;
	return 0;
}

int add_by_cin(){
		std::string mensagem;
		std::ofstream note("diario.txt", std::ios::app);
		if(!note.is_open()){
		  std::cerr << "E: Arquivo Nao Existente ou Inacessivel" << std::endl;
		  return 1;
		}
		std::cout << "Insira sua Mensagem: " << std::endl;
		std::getline(std::cin, mensagem);
		note << mensagem;
		note << std::endl;
		note.close();
		std::cout << "Arquivo Salvo Com Sucesso" << std::endl;
		return 0;
}

int add(int argc, char *argv[]){
   if(argc == 2){
    return add_by_cin();
   }
   if(!strcmp(argv[1], "add") && argc > 2){
    return add_by_arg(argv[2]);
   }
   if(!strcmp(argv[2], "add") && argc == 3){
    return add_by_cin();
   }
   if(!strcmp(argv[2], "add") && argc > 3){
    return add_by_arg(argv[3]);
   }
}

int list(int argc, char *argv[]){
  std::ifstream file;
  std::string note;
  int count = 0;
  file.open("diario.txt");
  if(!file.is_open()){
	  std::cerr << "E: Arquivo Nao Existente ou Inacessivel" << std::endl;
	  return 1;
	}
  while(!file.eof()){
    std::getline(file, note);
    if(note.size() == 0){
      continue;
    }
    ++count;
    std::cout << count << ". " << note << std::endl;
  }
  return 0;
}
/*
int command(int argc, char *argv[]){
  if(argc == 2){
    std::cout << "Insira Seu Comando: ";
    std::string comando;
    std::cin >> comando;
    if("add" == comando){
      return add(argc, argv);
    }
    if("list" == comando){
      return list(argc, argv);
    }
  }
  if(!strcmp(argv[2], "add")){
		return add(argc, argv);
	}
	if(!strcmp(argv[2], "list")){
		return list(argc, argv);
  }
}
*/
int main(int argc, char *argv[]){
	if(argc == 1){
		std::cout << "Uso: " << argv[0] << " <add/list>" << std::endl;
		return 1;
	}
	if(!strcmp(argv[1], "add")){
		add(argc, argv);
		return 0;
	}
	if(!strcmp(argv[1], "list")){
		list(argc, argv);
		return 0;
	}
	/*if(!strcmp(argv[1], "command")){
		command(argc, argv);
		return 0;
	}
	*/
	std::cout << "Uso: " << argv[0] << " <add/list>" << std::endl;
	return 1;
}
