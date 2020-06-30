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

Message* App::search_message(const std::string word)
{
    std::size_t found;
    for (size_t i = 0; i < diary.messages_size; ++i) {
        found = diary.messages[i].content.find(word);
        if (found != std::string::npos && &diary.messages[i] != nullptr){
              std::cout << "Found: " << std::endl;
              std::cout << diary.messages[i].content << std::endl;
              std::cout << "At: " << &diary.messages[i].content << std::endl;
              return &diary.messages[i];
        }
        std::cout << "Input Not Found" << std::endl;
        return nullptr;
    }
}

int App::show_usage()
{
    return 1;
}
