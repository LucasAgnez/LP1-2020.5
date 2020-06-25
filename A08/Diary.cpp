#include "Diary.h"

Diary::Diary(const std::string& name) : filename(name), messages(nullptr), messages_size(0), messages_capacity(10)
{
    messages = new Message[messages_capacity];
}

Diary::~Diary()
{
    delete[] messages;
}

void Diary::add(const std::string& message)
{
    if (messages_size >= messages_capacity) {
        return;
    }

    Message msg;
    msg.content = message;

    
    std::string current_date = get_current_date();
    std::string current_time = get_current_time();

    msg.date.set_from_string(current_date);
    msg.time.set_from_string(current_time);
    
    messages[messages_size] = msg;
    messages_size++;
}

void Diary::write()
{
    // gravar as mensagens no disco
}
