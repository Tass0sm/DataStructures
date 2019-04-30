#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node {
  int data = 0;
  node *next = NULL;
};

class LinkedList {
private:
  int length = 0;
  int item;
  node *head, *previous, *current;

public:
  void renew() {
    length = 0;
    head = NULL;
    previous = NULL;
    current = NULL;
  }

  int getLength() {
    return length;
  }
  
  bool empty() {
    return length == 0;
  }

  bool atEnd() {
    return current == NULL;
  }

  void next() {
    if (current != NULL) {
      node *temp = current;
      current = current->next;
      previous = temp;
    }
  }

  void first() {
    if (head != NULL) {
      current = head;
      previous = NULL;
    }
  }

  int retrieve() {
    if (current != NULL) {
      return current->data;
    }
    return 0;
  }

  void insert(int inData) {
    node *newNode = new node;
    newNode->data = inData;

    if (previous != NULL && current != NULL) {
      cout << "ONE EXECUTING" << endl;
      previous->next = newNode;
      newNode->next = current;
      cout << "ONE EXECUTED" << endl;
    } else if (previous == NULL && current == NULL) {
      cout << "TWO EXECUTING" << endl;
      head = newNode;
      current = newNode;
      cout << "TWO EXECUTED" << endl;
    } else if (previous == NULL && current != NULL) {
      cout << "THREE EXECUTING" << endl;
      head = newNode;
      newNode->next = current;
      cout << "THREE EXECUTED" << endl;
    } else if (previous != NULL && current == NULL) {
      cout << "FOUR EXECUTING" << endl;
      previous->next = newNode;
      current = newNode;
      cout << "FOUR EXECUTED" << endl;
    }
    length++;
  }

  void remove() {
    if (current != NULL) {
      current = (*current).next;
      (*previous).next = current;
    }
    length--;
  }

  void display() {
    first();
    for (int i = 0; i < length; i++) {
      cout << (*current).data << endl;
      cout << (*current).next << endl;
      next();
      cout << "\n";
    }
    cout << "\n";
  }

};


int main(int argc, char *argv[]) {
  LinkedList test;
  test.renew();

  cout << "Enter integer values until done. Quit by inputting 'q'." << endl;

  
	 
  test.insert(1);
  test.next(); 
  test.insert(2);
  test.next();
  test.insert(6);

  cout << test.retrieve() << endl;
  test.first();
  cout << test.retrieve() << endl;
  
  return 0;
}
