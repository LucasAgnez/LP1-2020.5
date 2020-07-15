#ifndef W5_LINE_H
#define W5_LINE_H

#include <iostream>

template <class X>
class Line
{
private:
  int size;
  int top;
  X *clients;

public:
  Line(int size);

  void push(X element);
  void pop();
  bool is_empty();
  X back();
  
  int get_size();
  void set_size(int size);
  int get_top();
  void set_top(int top);
  X* get_clients();
  void set_clients(X *c);
};

#endif
