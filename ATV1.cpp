#include<iostream>
#include<fstream>
#include<string.h>
#include<ctime>

std::string format_current_date(const std::string &format) {
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() { return format_current_date("%d/%m/%Y"); }

std::string get_current_time() { return format_current_date("%H:%M:%S"); }


int verify_date(){
  std::string note;
  std::string dia = get_current_date();
  std::ifstream file;
  dia = " # " + dia;	
  file.open("diario.md");
  if(!file.is_open()){
	  std::cerr << "E: Arquivo Nao Existente ou Inacessivel" << std::endl;
	  return 1;
	}
  while(!file.eof()){
    std::getline(file, note);
    if(dia == note){
      return 0;
    } 
   }
  return 1;
}

int add_by_arg(char arg[]){
	std::ofstream file("diario.md", std::ios::app);
	std::string dia, note, hora;
	if(!file.is_open()){
	  std::cerr << "E: Arquivo Nao Existente ou Inacessivel" << std::endl;
	  return 1;
  }
  int data = 0;  
  if (verify_date()){
    file << std::endl << " # " << get_current_date() << std::endl << std::endl;
	}
	file << "- " << get_current_time() << " " << arg << std::endl;
	file.close();
	std::cout << "Arquivo Salvo Com Sucesso" << std::endl;
	return 0;
}

int add_by_cin(){
	std::string mensagem, note;
	std::ofstream file("diario.md", std::ios::app);
	if(!file.is_open()){
	  std::cerr << "E: Arquivo Nao Existente ou Inacessivel" << std::endl;
	  return 1;
  }

	std::cout << "Insira sua Mensagem: " << std::endl;
	std::getline(std::cin, mensagem);
	
  if (verify_date()){
    file << std::endl << " # " << get_current_date() << std::endl << std::endl;
  }
  file << "- " << get_current_time() << " " << mensagem << std::endl;
	file.close();
	std::cout << "Arquivo Salvo Com Sucesso" << std::endl;
	return 0;
 }

int add(int argc, char *argv[]){
   if(argc == 2){
    return add_by_cin();
   }
   if(argc > 2){
    return add_by_arg(argv[2]);
   }
}

int list(int argc, char *argv[]){
  std::ifstream file;
  std::string note;
  file.open("diario.md");
  if(!file.is_open()){
	  std::cerr << "E: Arquivo Nao Existente ou Inacessivel" << std::endl;
	  return 1;
	}
	char space = ' ';
  while(!file.eof()){
    std::getline(file, note);
    if(note.size() == 0 || note.at(0) == space){
      continue;
    }
    std::cout << note << std::endl;
  }
  return 0;
}

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
	std::cout << "Uso: " << argv[0] << " <add/list>" << std::endl;
	return 1;
}
