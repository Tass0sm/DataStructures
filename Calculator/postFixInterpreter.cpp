k#include <stdio.h>
#include <iostream>
#include <string>
#include "calcStack.h"
using namespace std;

int main(int argc, char *argv[]) {
  stack myStack;
  myStack.create();

  std::string expression;
  while (myStack.getLength() < 7) {
    getline(cin, expression);
    if (expression == "exit") {
      break;
    }
    
    std::string command = "";
    int index = 0;
    while (index < expression.length() + 1) {
      if (index == expression.length()) {
	if (command == "+") {
	  myStack.add();
	} else if (command == "-") {
	  myStack.subtract();
	} else if (command == "*") {
	  myStack.multiply();
	} else if (command == "/") {
	  myStack.divide();
	} else if (command == "") {
	} else {
	  int pInt = std::stoi(command);
	  myStack.push(pInt);
	}
	command.clear();
	index++;
      } else {
	if (std::isspace(expression.at(index))) {
	  if (command == "+") {
	    myStack.add();
	  } else if (command == "-") {
	    myStack.subtract();
	  } else if (command == "*") {
	    myStack.multiply();
	  } else if (command == "/") {
	    myStack.divide();
	  } else {
	    int pInt = std::stoi(command);
	    myStack.push(pInt);
	  }
	  command.clear();
	} else {
	  command += expression.at(index);	
	}
	index++;
      }
    }
    cout << "Stack Length: ";
    cout << myStack.getLength() << endl;
    cout << "Stack Top: ";
    cout << myStack.peak() << endl;
  }
  

  return 0;
}
