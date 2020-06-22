#ifndef MESSEGE.H
#define MESSEGE.H
  
#include<string>

struct Date{
  int day;
  int month;
  int year;
};

struct Time {
  int hour;
  int min;
  int sec;
};

struct Messege{
  Date date;
  Time time;
  std::string content;
};

int verify_date();

int verify_time();
  
#endif
