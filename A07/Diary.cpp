#include "Diary.h"

Diary::Diary(const std::string& filename) : filename(filename), messages_size(0), messages_capacity(10), messages(nullptr)
{
  messages = new Message[messages_capacity];
}

void Diary::add(const std::string& message)
{
	if (messages_size >= messages_capacity){
    Message* message2 = new Message[messages_size*2];
    std::copy(messages, messages + messages_size, message2);
    delete[] messages;
    messages = message2;
    delete[] message2;
  }

  messages[messages_size].content = message;
  messages_size++;
}


void Diary::write()
{
    // gravar as mensagens no disco
}
