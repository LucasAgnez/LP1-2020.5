#include "Line.h"


template <class X>
Line<X>::Line(int size) : size(size), top(-1)
{
}

template <class X>
void Line<X>::push(X element){
  if(this->top == (this->size -1)){
    std::cout << "Fila cheia" << std::endl;
  }else{
    this->clientes[++this->top] = element;
  }
}

template <class X>
void Line<X>::pop(){
  if(this->top == -1){
    std::cout << "Fila vazia" << std::endl;
  }else{
    this->clientes[this->top--];
  }
}

template <class X>
bool Line<X>::is_empty(){
  if(this->top == -1){
    return true;
  }else{
    return false;
  }
}

template <class X>
X Line<X>::back(){
  return this->clients[this->top];
}

template <class X>  
int Line<X>::get_size() {
  return this->size;
}

template <class X>
void Line<X>::set_size(int size) {
  this->size = size;
}

template <class X>
int Line<X>::get_top() {
  return this->top;
}

template <class X>
void Line<X>::set_top(int top) {
  this->top = top;
}

template <class X>
X* Line<X>::get_clients() {
  return this->clients;
}

template <class X>
void Line<X>::set_clients(X *c) {
  this->clients = c;
}
