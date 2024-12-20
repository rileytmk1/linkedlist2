#include "Node.h"
#include "Student.h"
#include <iostream>
#include <cstring>

using namespace std;

Node* head = NULL;

int main()
{
  char* input [10];
  cout << "ADD, PRINT, DELETE, or AVERAGE?" << endl;
  cin.get(input, 10);
  cin.get();
  while (strcmp(input, "QUIT") != 0) {
    if (strcmp(input, "ADD") == 0) {
      char* fname [20];
      char* lname [20];
      int id;
      double gpa;
    
      cout << "First Name: ";
      cin.get(fname, 20);
      cin.get();
    
      cout << "Last Name: ";
      cin.get(lname, 20);
      cin.get();

      cout << "ID: ";
      cin >> id;
      cin.ignore();

      cout << "GPA: ";
      cin >> gpa;
      cin.ignore();

      Student* student = new Student();
      student->setID(id);
      student
	}
    if (strcmp(input, "PRINT") == 0) {
      print(head);
    }
  }
  

    
}

void add (Student* newstudent){
  Node* current = head;
  Node* t = NULL;
  if (current == NULL) {
    head = new Node(newstudent);
  }
  else if (current->getStudent()->getID() > newstudent->getID()){
    t = current;
    current = new Node(newstudent);
    add(t->getStudent());
    
  }
  else{
    while (current->getNext() != NULL){
      current = current->getNext();
    }
    current->setNext() = new Node(newstudent);
    else{
      
    }

    // 4 (6)
    // 4 --> 6 (5)
    //4 --> 5 --> 6
    
  }
}

void print(Node* next){
  if (next != NULL){
    Student* student = next->getStudent();
    cout << student->getFirst() << ", ";
    cout << student->getLast() << ", ";
    cout << student->getId() << ", ";
    cout << student->getGPA() << endl;
    print(next->getNext());
  }
}

