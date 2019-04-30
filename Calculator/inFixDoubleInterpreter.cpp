#include <stdio.h>
#include <iostream>
#include <string>
#include "calcStack.h"
using namespace std;

std::string operationToPost(std::string term, string op) {
  std::string operandOne;
  std::string operandTwo;

  int opPos = term.find_first_of(op);
  char realOp = term[opPos];
  operandOne = term.substr(0, opPos-1);
  operandTwo = term.substr(opPos+1, term.length() - (opPos+1));
  return (operandOne != "v"? operandOne : "") + (operandTwo != " v"? operandTwo : "") + " " + realOp + " ";
}

int evaluateTerm(std::string term, string op) {
  stack myStack;
  myStack.create();

  std::string expression = operationToPost(term, op);
  //  cout << expression << endl;
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
	} else if (command == "") {
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
  return myStack.peak();
}

std::string inToPostFix(std::string inFix) {
  std::string postFix = "";

  //MD
  int mdPos = inFix.find_first_of("*/");
  while (mdPos != std::string::npos) {
    int termBeg = inFix.find_last_of("1234567890", mdPos);
    while (inFix.find_last_of("1234567890", termBeg-1) == termBeg-1) {
      termBeg--;
    }
    int termLen = (inFix.find_first_of("1234567890", mdPos)+1) - termBeg;
    while (inFix.find_first_of("1234567890", termBeg+termLen) == (termBeg+termLen)) {
      termLen++;
    }
    std::string term = inFix.substr(termBeg, termLen);
    std::string evalToString = std::to_string(evaluateTerm(term, "*/"));
    inFix.replace(termBeg, termLen, evalToString);
    
    mdPos = inFix.find_first_of("*/");
  }

  int asPos = inFix.find_first_of("+-");
  while (asPos != std::string::npos) {
    int termBeg = inFix.find_last_of("1234567890", asPos);
    while (inFix.find_last_of("1234567890", termBeg-1) == termBeg-1) {
      termBeg--;
    }
    int termLen = (inFix.find_first_of("1234567890", asPos)+1) - termBeg;
    while (inFix.find_first_of("1234567890", termBeg+termLen) == (termBeg+termLen)) {
      termLen++;
    }
    std::string term = inFix.substr(termBeg, termLen);
    std::string evalToString = std::to_string(evaluateTerm(term, "+-"));
    inFix.replace(termBeg, termLen, evalToString);

    asPos = inFix.find_first_of("+-");
  }

  return inFix;
}

int main(int argc, char *argv[]) {
  std::string expression;
  while (expression != "exit") {
    getline(cin, expression);
    cout << inToPostFix(expression) << endl;
  }    

  return 0;
}
