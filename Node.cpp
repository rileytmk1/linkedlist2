//Brandon's Code

#include "Node.h"
#include "Student.h"

Node::Node(Student* newStudent) {
  value = newStudent;
  next = NULL;
}

Node::~Node() {
  delete value;
  next = NULL;
}

void Node::setValue(Student* newStudent) {
  value = newStudent;
}

Student* Node::getValue() {
  return value;
}

void Node::setNext(Node* newNext) {
  next = newNext;
}

Node* Node::getNext() {
  return next;
}
