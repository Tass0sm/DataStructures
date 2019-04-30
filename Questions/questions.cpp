#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct node {
  bool qNode;
  std::string data;
  node *left = NULL;
  node *right = NULL;
};

class tree {
private:
  node *root;
  node *current;
public:
  void create() {
    root = NULL;
    current = root;
  }

  node *getRoot() {
    return root;
  }

  node *getCurrent() {
    return current;
  }
  
  bool empty() {
    return root == NULL;
  }

  void read() {
    
  }
  
  void write() {
    
  }

  void playGame() {
    if (current == NULL) {
      std::cout << "This node is NULL\nWhat was your animal?\n" << endl;
      std::string realAnimal;
      std::cin >> realAnimal;
      
      node *newNode = new node;
      newNode->data = realAnimal;
      newNode->qNode = false;
      newNode->left = NULL;
      newNode->right = NULL;

      current = newNode;
    } else if (current->qNode) {
      std::cout << current->data << " (Y/N)" << endl;

      char ans;
      cin >> ans;
      
      if (ans == 'Y') {
      	current = current->right;
        playGame();
      } else {
      	current = current->left;
        playGame();
      }
    } else {
      std::cout << "Was your animal a(n) " << current->data << "?" << endl;
            
      char ans;
      cin >> ans;
      
      if (ans == 'N') {
      	std::cout << "What was your animal?" << endl;
	std::string perc = current->data;
	std::string realAnimal;
	std::cin >> realAnimal;
	
	std::cout << "Give a question that a " << realAnimal <<
	  " satisfies and a " << perc << " does not satisfy." << endl;
	std::string question;
	std::cin.ignore();
	std::getline(std::cin, question);
      
      	node *leftNode = new node;
      	leftNode->data = perc;
      	leftNode->qNode = false;
	leftNode->left = NULL;
      	leftNode->right = NULL;
      	node *rightNode = new node;
      	rightNode->data = realAnimal;
      	rightNode->qNode = false;
	rightNode->left = NULL;
	rightNode->right = NULL;
      	node *newQuestionNode = new node;
      	newQuestionNode->data = question;
      	newQuestionNode->qNode = true;
      	newQuestionNode->left = leftNode;
      	newQuestionNode->right = rightNode;
      	current = newQuestionNode;
      } else {
      	cout << "Victory" << endl;
      }
    }

    if (root == NULL) {
      root = current;
    }
  }
};

int main(int argc, char *argv[]) {
  std::ifstream infile("tree.txt");

  std::string line;
  while (std::getline(infile, line)) {
    int i = line.find(",");

    std::string treeIndex = line.substr(0, i);
    cout << treeIndex << endl;

    
    
    //int a, b;
    //if (!(iss >> a >> b)) {
    //  break;
    //} // error

    // process pair (a,b)
  }
    
    
  tree myTree;
  myTree.create();
  
  cout << "**** NEW GAME ****\nThink of an animal." << endl;
  myTree.playGame();

  cout << "**** NEW GAME ****\nThink of an animal." << endl;
  myTree.playGame();

  cout << "**** NEW GAME ****\nThink of an animal." << endl;
  myTree.playGame();

  cout << "**** NEW GAME ****\nThink of an animal." << endl;
  myTree.playGame();

  cout << "**** NEW GAME ****\nThink of an animal." << endl;
  myTree.playGame();

  cout << "**** NEW GAME ****\nThink of an animal." << endl;
  myTree.playGame();

}


