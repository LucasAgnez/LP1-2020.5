#ifndef W5N_APP_H
#define W5N_APP_H

#include "Diary.h"

#include <string>

struct App
{
    Diary diary;

    App(const std::string& filename);
    int run(int argc, char* argv[]);
    void add();
    void add(const std::string message);
    void list_messages();
    void list_messages(const std::string format);
    void search_message();
    std::vector<Message*> search_message(const std::string word);
    void interactive();
    int show_usage(std::string name);
};
#endif
