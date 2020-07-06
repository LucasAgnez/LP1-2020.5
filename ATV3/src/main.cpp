#include "App.h"

inline bool exists(const std::string& name);
void set_config();
std::string set_path();

int main(int argc, char* argv[])
{
  set_config();
  std::string path = set_path();
  App aplicativo(path);
  return aplicativo.run(argc, argv);
}


inline bool exists(const std::string& name)
{
  std::ifstream f(name.c_str());
  return f.good();
}

void set_config()
{
  if(!exists("diary.config")){
    std::ofstream conf;
    conf.open("diary.config");
    conf << "path=diary.md" << std::endl;
    conf << "default_format=[%d %t] %m" << std::endl;
    conf.close();
  }
}

std::string set_path(){
  std::ifstream file;
  std::string path;
  file.open("diary.config");
  size_t found;
  while(!file.eof()){
    std::getline(file, path);
    if(path.size() == 0){
      continue;
    }
    found = path.find("path");
    if(found != std::string::npos){
      size_t pos = path.find("=");
      path.erase(0,pos+1);
      while(true){
        if(path.at(0) == ' '){
          path.erase(0, 1);
        }
        else
          break;
      }
      return path;
    }
  }
}
