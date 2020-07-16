#if !defined(VECTORSUPERMERCADO_H)
#define VECTORSUPERMERCADO_H

#include <iostream>

template <class T>
class VectorSupermercado
{
private:
  T* elementos;
  size_t size;
  size_t capacity;

  void aumentaCapacity();
public:

  VectorSupermercado();
  VectorSupermercado(size_t size);
  ~VectorSupermercado();

  void push(T elemento);
  void pop();
  T* at(size_t index);
  bool isEmpty();

  T* getElementos() {
    return this->elementos;
  }
  size_t getSize() {
    return this->size;
  }
  size_t getCapacity() {
    return this->capacity;
  }
};

#endif // VECTORSUPERMERCADO_H
