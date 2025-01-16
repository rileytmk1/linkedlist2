//Brandon's Code

#ifndef NODE_HEADER
#define NODE_HEADER
#include <iostream>
#include "Student.h"
using namespace std;

class Node {
 public:
  Node(Student* newStudent);
  ~Node();
  void setValue(Student* newStudent);
  Student* getValue();
  void setNext(Node* newNext);
  Node* getNext();
 private:
  Student* value;
  Node* next;
};
#endif
