#include "Node.h"
#include "Student.h"
#include <iostream>
#include <cstring>

using namespace std;


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

void add (Student* newstudent, Node* current, Node* previous){
  if (current == NULL && previous == NULL) {
    current = new Node(newstudent);
  }
  else if (current != NULL && previous == NULL){
    if (current->getStudent()->getID() > newstudent->getID()){
      Node* temp = NULL;
      temp = current;
      current = new Node(newstudent);
      current->setNext(temp);
    }
    else {
      Node* newprev = current;
      Node* newcurr = current->getNext();
      add(newstudent, newcurr, newprev);
    }
  }
  else if (current->getStudent()->getID() > newstudent->getID()){
    Node* temp2 = NULL;
    temp2 = current;
    current = new Node(newstudent);
    previous->setNext(current);
    current->setNext(temp2);
  }
  else{
    Node* newprev2 = current;
    Node* newcurr2 = current->getNext();
    add(newstudent, newcurr2, newprev2);
  }
}

void average()
{

}

void delete()
{

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

