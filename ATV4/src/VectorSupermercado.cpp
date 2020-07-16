#include "VectorSupermercado.h"

template <class T>
VectorSupermercado<T>::VectorSupermercado()
  : size(0),
    capacity(1), 
    elementos(nullptr)
{
  this->elementos = new T[this->capacity];
}

template <class T>
VectorSupermercado<T>::~VectorSupermercado() 
{
  delete[] this->elementos;
}

template <class T>
void VectorSupermercado<T>::aumentaCapacity() {
  this->capacity *= 2;

  T* aux_elemento = new T[this->capacity];
  std::copy(this->elementos, this->elementos + this->size, aux_elemento);
  delete[] this->elementos;
  this->elementos = aux_elemento;
}

template <class T>
void VectorSupermercado<T>::push(T elemento){
  this->elementos[this->size] = elemento;
  this->size++;
  
  if (this->size == this->capacity) {
    this->aumentaCapacity();
  }
}

template <class T>
void VectorSupermercado<T>::pop(){
  if(this->size == 0){
    // Lançar exceção
    return;
  }

  delete this->elementos[this->size-1];
  this->size--;
}

template <class T>
T* VectorSupermercado<T>::at(size_t index) { 
  if (index >= this->size) {
    //Lança esceção
    return nullptr;
  }
  return this->elementos[index]; 
} 

template <class T>
bool VectorSupermercado<T>::isEmpty(){
  return this->size > 0 ? false : true;
}