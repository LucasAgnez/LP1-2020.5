#ifndef W5N_DIARY_H
#define W5N_DIARY_H

#include "Message.h"

#include <fstream>
#include <string>

struct Diary
{
    Diary(const std::string& filename);
    ~Diary();

    void increase_array();
    std::string filename;
    Message* messages;
    size_t messages_size;
    size_t messages_capacity;
    void add(const Message& message);
    Message add(const std::string& message);
    bool verify_date(Message m);
    void write(Message m);
};
#endif
