#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student {
 public:
  Student();
  void setID(int newID);
  int getID();
 protected:
  int id;
};

#endif
