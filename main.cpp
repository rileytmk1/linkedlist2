#include "Node.h"
#include "Student.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

//function prototypes
void add(Student* newstudent, Node* &current, Node* previous);
void print(Node* next);
void average(Node* next, int count, double total);
void DELETE(int id, Node* &head, Node* previous); 

int main()
{
  Node* head = NULL;
  char input [10];
  while (strcmp(input, "QUIT") != 0) {
    cout << "ADD, PRINT, DELETE, AVERAGE, or QUIT?" << endl;
    cin.get(input, 10);
    cin.get();
    if (strcmp(input, "ADD") == 0) {
      char fname [20];
      char lname [20];
      int id;
      double gpa;

      //inputting student values
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

      Student* nstudent = new Student();
      nstudent->getId() = id;
      nstudent->getGPA() = gpa;
      strcpy(nstudent->getFirst(), fname);
      strcpy(nstudent->getLast(), lname);

      add(nstudent, head, NULL); //set previous to NULL
    }
    if (strcmp(input, "PRINT") == 0) {
      print(head);
    }
    if(strcmp(input, "AVERAGE") == 0) {
      average(head, 0, 0); //count and total start at 0
    }
    if(strcmp(input, "DELETE") == 0){
      int check_id;
      cout << "ID: ";
      cin >> check_id;
      cin.ignore();
      DELETE(check_id, head, NULL); //set previous to NULL
    }
  }
  

    
}


void add (Student* newstudent, Node* &current, Node* previous){
  if (current == NULL) { // At end of the list
    if (previous == NULL) { // List is empty
      current = new Node(newstudent); //add the first Node
    }
    else{ 
      previous->setNext(new Node(newstudent)); //add to end of list
    }
  }
  else if (current != NULL && previous == NULL){ //first item in the list
    if (current->getValue()->getId() > newstudent->getId()){ //set the new student to before the first if id is smaller
      Node* temp = NULL;
      temp = current;
      current = new Node(newstudent); //first node is the new one
      current->setNext(temp); //point to old one
    }
    else { // new student has greater id
      Node* newprev = current;
      Node* newcurr = current->getNext();
      add(newstudent, newcurr, newprev);
    }
  }

  else if (current->getValue()->getId() > newstudent->getId()){
    //insert before current node
    Node* temp2 = NULL;
    temp2 = current;
    current = new Node(newstudent);
    previous->setNext(current);
    current->setNext(temp2);
  }
  else{
    //call recursive to go keep going through the list
    Node* newprev2 = current;
    Node* newcurr2 = current->getNext();
    add(newstudent, newcurr2, newprev2);
  }
}

void average(Node* next, int count, double total)
{ 
  if (next != NULL){
    //recursively traverse the list until the end
    Student* student = next->getValue();
    total += student->getGPA(); //add up total gpa
    count++; //count how many students
    average(next->getNext(), count, total);
  }
  else{
    if (count == 0){
      cout << "No students." << endl;
    }
    else{
      double average = total/count;
      cout << "Average: " << fixed << setprecision(2) << average << endl;
    }
  }
    
}

void DELETE(int id, Node* &current, Node* previous)
{
  if (current == NULL){
    // Node not found
    cout << "No students." << endl;
    return;
  }
  if (current->getValue()->getId() == id){
    if (previous == NULL) { //head node
      Node* temp = current;
      current = current->getNext();
      delete temp;
    }
    else{ //not a head node
      Node* temp = current;
      previous->setNext(current->getNext()); //set the node before the one beign deleted to point to the one after
      delete temp;
    }
    return;
    
      
  }
  else{
    //recursively search for the next node
    Node* next = current->getNext();
    DELETE(id, next, current);
  }
  
}

void print(Node* next){ 
  if (next != NULL){
    Student* student = next->getValue();
    cout << student->getFirst() << ", ";
    cout << student->getLast() << ", ";
    cout << student->getId() << ", ";
    cout << fixed << setprecision(2) << student->getGPA() << endl;
    print(next->getNext());
  }
}

