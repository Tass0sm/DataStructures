#include <stdio.h>

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

  int getLength() {
    return length;
  }
  
  int peak() {
    return data[length-1];
  }

  void add() {
    int b = this->pop();
    int a = this->pop();
    this->push(a+b);
  }

  void subtract() {
    int b = this->pop();
    int a = this->pop();
    this->push(a-b);
  }

  void multiply() {
    int b = this->pop();
    int a = this->pop();
    this->push(a*b);
  }
  void divide() {
    int b = this->pop();
    int a = this->pop();
    this->push(a/b);
  }

  int* getDataPointer() {
    return data;
  }
};
