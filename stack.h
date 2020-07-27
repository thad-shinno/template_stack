#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "node.h"
using std::cout;
using std::endl;

// Last in first out templated stack

template <typename T>
class Stack {
  // stack has a top node and a size
  private:
    Node<T> *_top;
    int _size;

  public:
    Stack<T>();
    T pop();
    void push(T);
    T peek();
    int size();
    void print();
};

// initialize the size as zero
template <typename T>
Stack<T>::Stack() {
  _size = 0;
}

// return remove the top node
template <typename T>
T Stack<T>::pop() {
  // can't pop an empty stack
  if (_size == 0) {
    throw "Stack is Empty!";
  }
  
  T val = _top->getVal();
  _top = _top->getNext();
  _size--;
  return val;
}

// push a new node to the top of the stack
template <typename T>
void Stack<T>::push(T val) {
  Node<T> *n = new Node<T>(val);
  // the node becomes the top of an empty stack 
  if (_size == 0) {
    _top = n;
  }
  // set the node's next to be top. The top is the new node.
  else {
    n->setNext(_top);
    _top = n;
  }
  _size++;
}

// return the top node value
template <typename T>
T Stack<T>::peek() {
  // can't peek an empty stack
  if (_size == 0) {
    throw "Stack is Empty!";
  }
  
  return _top->getVal();
}

template <typename T>
int Stack<T>::size() {
  return _size;
}

template <typename T>
void Stack<T>::print() {
  // since the whole stack is backwards, make a teemp array
  T printarr[_size];
  // fill the array with the stack backwards
  Node<T> *curr = _top;
  for (int i = _size - 1; i >= 0; i--) {
    printarr[i] = curr->getVal();
    curr = curr->getNext();
  }
  // print the array
  cout << "Stack: ";
  for (int i = 0; i < _size; i++) {
    cout << printarr[i] << " ";
  }
  cout << endl;
}

#endif
