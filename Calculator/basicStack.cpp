#include <stdio.h>
#include <iostream>
using namespace std;

class stack {
private:
  int length;
  int *head;
  int data[ 8 ];

public:
  void create() {
    for (int i = 0; i < (sizeof(data)/sizeof(*data)); i++) {
      data[i] = 0;
    }
    length = 0;
    head = &data[0];
  }

  bool empty() {
    return length == 0;
  }
  
  void push(int p) {
    *head = p;
    length++;
    head = &data[length];    
  }
  
  int pop() {
    if (length > 0) {
      length--;
      head = &data[length];
      return *head;
    }
    return 0;
  }
};

int main(int argc, char *argv[]) {
  stack myStack;
  myStack.create();
  myStack.push(2);
  myStack.push(3);
  cout << myStack.pop() + myStack.pop();
  return 0;
}
