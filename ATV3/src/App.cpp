#include "App.h"

#include <iostream>
#include <string>

App::App(const std::string& filename) : diary(filename)
{
}

int App::run(int argc, char* argv[])
{
    if (argc == 1) {
        return show_usage(argv[0]);
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        if(argc == 2) {
           list_messages();
        } else {
            list_messages(argv[2]);
       }
    } else if (action == "search") {
        if (argc == 2) {
            search_message();
        } else {
            search_message(argv[2]);
        }
    } else if(action == "interactive"){
        interactive();
    }
    else {
        return show_usage(argv[0]);
    }

    return 0;
}

void App::add()
{
    std::string message;
    std::cout << "Enter your message:" << std::endl;
    std::getline(std::cin, message);

    add(message);
}

void App::add(const std::string message)
{
    Message m = diary.add(message);
    diary.write(m);
}

void App::list_messages()
{
  std::string config;
  std::ifstream file;
  file.open("diary.config");
  size_t found;
  while(!file.eof()){
    std::getline(file, config);
    if(config.size() == 0){
      continue;
    }
    found = config.find("default");
    if(found != std::string::npos){
      size_t pos = config.find("=");
      config.erase(0,pos+1);
      list_messages(config);
      break;
    }
  }
  return;
}

void App::list_messages( std::string format)
{
  Message message;
  format = format + " ";
  for (size_t j = 0; j < diary.messages_size; ++j) {
    message = diary.messages[j];
    for (size_t i = 0; i < size_t(format.size()); ++i) {
      if(format.at(i) == '%' && format.at(i+1) == 'd'){
        std::cout << diary.messages[j].date.to_string();
        i++;
      }
      else if(format.at(i) == '%' && format.at(i+1) == 't'){
        std::cout << diary.messages[j].time.to_string();
        i++;
      }
      else if(format.at(i) == '%' && format.at(i+1) == 'm'){
        std::cout << diary.messages[j].content;
        i++;
      }
      else{
        std::cout << format.at(i);
      }
    }
    std::cout << std::endl;
  }
}

void App::search_message(){
      std::string word;
      std::cout << "Enter what youre looking for:" << std::endl;
      std::getline(std::cin, word);
      search_message(word);
}


std::vector<Message*> App::search_message(const std::string word)
{
    std::size_t found;
    int did_find = 0;
    std::vector<Message*> msgs_pointers;
    for (size_t i = 0; i < diary.messages_size; ++i) {
        found = diary.messages[i].content.find(word);
        if (found != std::string::npos && &diary.messages[i] != nullptr){
              msgs_pointers.push_back(&diary.messages[i]);
              did_find++;
        }
    }
    if(did_find){
      std::cout << "Total of " << did_find << " Matches" << std::endl;
      for(int i = 0; i < did_find; ++i){
        std::cout << i+1 << ". " << msgs_pointers[i]->content << std::endl;
      }
      return msgs_pointers;
    }
    std::cout << "Input Not Found" << std::endl;
    return msgs_pointers;
}

void App::interactive()
{
  int command;
  std::cout << std::endl;
  std::cout << "Diary" << std::endl;
  while(true){
    std::cout << std::endl;
    std::cout << "1) List Current Messages" << std::endl;
    std::cout << "2) Add a Message" << std::endl;
    std::cout << "3) Search Messages"<< std::endl;
    std::cout << std::endl;
    std::cout << "0) Exit"  << std::endl;
    std::cin >> command;
    std::string bin;
    if (command == 0)
      break;
    if(command == 1 ){
      getline(std::cin, bin);
      list_messages();
    }else if(command == 2){
      getline(std::cin, bin);
      add();
    }else if(command == 3){
      getline(std::cin, bin);
      search_message();
    }
  }
}

int App::show_usage(std::string name)
{
  std::cout << "Usage: " << name << " <add/list/search>" << std::endl;
  return 1;
}
