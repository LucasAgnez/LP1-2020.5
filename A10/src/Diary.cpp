#include "Diary.h"

Diary::Diary(const std::string& name) : filename(name), messages(nullptr), messages_size(0), messages_capacity(10)
{
    std::ofstream note(filename, std::ios::app);
	  if(!note.is_open()){
	    std::cerr << "E: File Doesnt Exist or Cannot be Accessed" << std::endl;
	    return;
    }
    std::string msg, content;
    std::ifstream file(filename);
    messages = new Message[messages_capacity];
    Date date;
    Time time;
    while(!file.eof()){
      if(messages_size >= messages_capacity){
         increase_array();
         continue;
      }
      getline(file, msg);
      if (msg.size() == 0) {
        continue;
      }
      if(msg.at(0) == '#'){
        date.set_from_string(msg);
      }
      else if (msg.at(0) == '-'){
        std::stringstream stream(msg.substr(1));
        time.set_from_string(stream);
        std::getline(stream, content);
        messages[messages_size].date = date;
        messages[messages_size].time = time;
        messages[messages_size].content = content;
        messages_size++;
      }
    }

}

Diary::~Diary()
{
    delete[] messages;
}


void Diary::increase_array(){
   Message *messages2;
   messages2 = new Message[messages_capacity*2];
   for(int i = 0; i < messages_capacity; i++){
     messages2[i] = messages[i];
   }
   messages_capacity = messages_capacity*2;
   delete[] messages;
   messages = messages2;
}

Message Diary::add(const std::string& message)
{
  if(messages_size >= messages_capacity){
       increase_array();
   }
  if (messages_size < messages_capacity) {
    Message m;
    m.content = message;
    
    std::string current_date = get_current_date();
    std::string current_time = get_current_time();

    m.date.set_from_string(current_date);
    m.time.set_from_string(current_time);

    messages[messages_size] = m;
    messages_size++;
    return m;        
  }

}


bool Diary::verify_date(Message m){
  std::string note;
  std::string dia = m.date.to_string();
  std::ifstream file;
  dia = "# " + dia;	
  file.open(filename);
  while(!file.eof()){
    std::getline(file, note);
    if(dia == note){
      return false;
    }if (note.size() == 0) {
      continue;
    }
   }
  return true;
}

void Diary::write(Message m)
{
	  std::ofstream file(filename, std::ios::app);
    if (verify_date(m)){
      file << std::endl << "# " << m.date.to_string() << std::endl << std::endl;
	  }
	  file << "- " << m.time.to_string() << " " << m.content << std::endl;
	  file.close();
	  std::cout << "File is Successfully Saved" << std::endl;
}

