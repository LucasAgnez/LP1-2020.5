#include "App.h"

#include <iostream>
#include <string>

App::App(const std::string& filename) : diary(filename)
{
}

int App::run(int argc, char* argv[])
{
    if (argc == 1) {
        return show_usage();
    }

    std::string action = argv[1];

    if (action == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (action == "list") {
        list_messages();
    } else if (action == "search") {
        if (argc == 2) {
            search_message();
        } else {
            search_message(argv[2]);
        }
    } else {
        return show_usage();
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
    for (size_t i = 0; i < diary.messages_size; ++i) {
        const Message& message = diary.messages[i];
        std::cout << "-" << message.content << std::endl;
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

int App::show_usage()
{
  std::cout << "Usage: ./program <add/list/search>" << std::endl;
  return 1;
}
