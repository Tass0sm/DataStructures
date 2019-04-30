#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node {
  int cData = 0;
  int eData = 0;
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
      return current->cData;
    }
    return 0;
  }

  void insert(int coeffData, int expData) {
    node *newNode = new node;
    newNode->cData = coeffData;
    newNode->eData = expData;

    if (previous != NULL && current != NULL) {
      previous->next = newNode;
      newNode->next = current;
    } else if (previous == NULL && current == NULL) {
      head = newNode;
      current = newNode;
    } else if (previous == NULL && current != NULL) {
      head = newNode;
      newNode->next = current;
    } else if (previous != NULL && current == NULL) {
      previous->next = newNode;
      current = newNode;
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

  void expSort() {
    for (int i = 0; i < length; i++) {
      first();

      for (int k = 1; k < i; k++) {
	next();
      }
      
      node* origin = current;

      if (i != 0) {
	next();
      }
      node* highest = current;

      for (int j = i; j < length; j++) {
	if (current) {
	  if (current->eData > highest->eData) {
	    highest = current;
	  }
	}
	next();
      }

      if (highest != origin) {
	if (i == 0) {
	  head = highest;
	  origin->next = highest->next;
	  highest->next = origin;
	} else {
	  highest->next = origin->next;
	  origin->next = highest;
	}
      }
      display();
    }
  }
  
  void display() {
    first();
    for (int i = 0; i < length; i++) {
      if (current->cData > 0) {
	if (current->cData > 1) {
	  cout << current->cData;
	}
	if (current->eData > 0) {
	  cout << "x";
	}
	if (current->eData > 1) {
	  cout << "^";
	  cout << current->eData;
	}

	if (i < length-1) {
	  cout << " + ";
	}
      }

      next();
    }
    cout << "\n";
  }

};


int main(int argc, char *argv[]) {
  LinkedList test;
  test.renew();

  cout << "Enter integer values until done. Quit with 'n'." << endl;

  int c = 0;
  int e = 0;
  char f = 'y';
  while (f == 'y') {
    cout << "Enter term coefficient." << endl;
    cin >> c;
    cout << "Enter term exponent." << endl;
    cin >> e;
    test.insert(c, e);
    test.next();
    cout << "\nContinue? (y/n)" << endl;
    cin >> f;
  }

  test.expSort();
  test.display();
  
  return 0;
}
