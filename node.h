// @author Thad Shinno
#ifndef NODE_H
#define NODE_H

// Node has a generic datatype value and a next node

template <typename T>
class Node {
  private:
    T _val;
    Node *_next;

  public:
    Node<T>(T);
    void setNext(Node*);
    Node<T>* getNext();
    T getVal();
};

template <typename T>
Node<T>::Node(T val) {
  _val = val;
}

template <typename T>
void Node<T>::setNext(Node<T> *next) {
  _next = next;
}

template <typename T>
Node<T>* Node<T>::getNext() {
  return _next;
}

template <typename T>
T Node<T>::getVal() {
  return _val;
}

#endif

