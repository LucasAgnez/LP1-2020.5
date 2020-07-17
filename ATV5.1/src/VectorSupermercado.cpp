#include "VectorSupermercado.h"
#include "Produto.h"

template <class T>
VectorSupermercado<T>::VectorSupermercado()
  : size(0),
    capacity(1),
    elementos(nullptr)
{
  this->elementos = new T[this->capacity];
}

template <class T>
VectorSupermercado<T>::VectorSupermercado(size_t s)
  : size(s),
    capacity(s*2 == 0 ? 1 : s*2),
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
    return;
  }
  this->size--;
}

template <class T>
T& VectorSupermercado<T>::at(size_t index) { 
  if (index >= this->size) {
    throw std::out_of_range("Index out of range.");
  }
  return this->elementos[index]; 
} 

template <class T>
bool VectorSupermercado<T>::isEmpty(){
  return this->size > 0 ? false : true;
}

/**
 * É preciso avisar previamente quais classes serão implementadas no template
 * Caso contrário, occore erro de undefined reference
 */
template class VectorSupermercado<Produto>;