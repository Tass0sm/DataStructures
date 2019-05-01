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

  void toString() {
    printf("{ NODE\n\tQuestion: %i,\n\tData: %s,\n\tLeft P: %i\n\tRight P: %i\n}\n",
	qNode, data.c_str(), left, right);
  }
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

  void readIndex(node *head, std::string index, node *newNode) {
    if (index.compare("-1") == 0) {
      root = newNode;
      cout << "SET ROOT" << endl;
      current = newNode;
      return;
    }

    char path = index.at(0);
    //cout << path << endl;
    if (index.length() > 1) {
      std::string remainder = index.substr(1);

      if (path == '0') {
	//cout << "DESCENDED LEFT" << endl;
	current = head->left;
	readIndex(head->left, remainder, newNode);
      } else if (path == '1') {
	//cout << "DESCENDED RIGHT" << endl;
	current = head->right;
	readIndex(head->right, remainder, newNode);
      } else {
	cout << "ERROR" << endl;
      }
      
    } else {
      //current->toString();
      if (path == '0') {
	//cout << "SET LEFT" << endl;
	current->left = newNode;
      } else if (path == '1') {
	//cout << "SET RIGHT" << endl;
	current->right = newNode;
      } else {
	cout << "ERROR" << endl;
      }
    }
  }
  
  void readLine(std::string line) {
    int commaPos = line.find(",");
    std::string treeIndex = line.substr(0, commaPos);
    std::string lineData = line.substr(commaPos + 2);
    int lineQNode = lineData.find("?");
    node *newNode = new node;
    newNode->data = lineData;
    newNode->qNode = (lineQNode == -1)? false : true;
    newNode->left = NULL;
    newNode->right = NULL;

    readIndex(root, treeIndex, newNode);
    //cout << "FINISHED LINE\n" << endl;
  }

  void read() {
    std::ifstream infile("tree.txt");
    std::string line;
    while (std::getline(infile, line)) {
      //      cout << line << endl;      
      reset();
      readLine(line);
    }
    current = root;
  }

  void truncOut() {
    std::ofstream outfile;
    outfile.open("tree.txt", fstream::trunc);
    outfile.close();
  }
  
  void writeNode(node *node, std::string treeIndex) {
    //cout << treeIndex << endl;
    //node->toString();
    std::ofstream outfile;
    outfile.open("tree.txt", fstream::app);
    std::string outLine = treeIndex + ", " + node->data + "\n";
    //cout << outLine;
    outfile << outLine;
    outfile.close();
  }
  
  void writeTree(node *head, std::string treeIndex) {
    writeNode(head, treeIndex);
    
    if (head->left != NULL) {
      writeTree(head->left, treeIndex + "0");
    }

    if (head->right != NULL) {
      writeTree(head->right, treeIndex + "1");
    }
  }
  
  void write() {
    writeNode(root, "-1");

    writeTree(root->left, "0");
    writeTree(root->right, "1");
  }

  void reset() {
    current = root;
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
	//current->toString();
	
	//Percieved Animal (Existing Node / LEFT)
	std::string perc = current->data;

	//Actual Animal (New Node / RIGHT)
      	std::cout << "What was your animal?" << endl;
	std::string realAnimal;
	std::cin >> realAnimal;

	//Distinguising Question (New Node / QUESTION)
	std::cout << "Give a question that a " << realAnimal <<
	  " satisfies and a " << perc << " does not satisfy." << endl;
	std::string question;
	std::cin.ignore();
	std::getline(std::cin, question);

	//Left
      	node *leftNode = new node;
      	leftNode->data = perc;
      	leftNode->qNode = false;
	leftNode->left = NULL;
      	leftNode->right = NULL;

	//Right
      	node *rightNode = new node;
      	rightNode->data = realAnimal;
      	rightNode->qNode = false;
	rightNode->left = NULL;
	rightNode->right = NULL;

	//Question
	current->data = question;  
	current->qNode = true;     
	current->left = leftNode;  
	current->right = rightNode;	
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


  tree myTree;
  myTree.create();
  myTree.read();

  cout << "**** NEW GAME ****\nThink of an animal." << endl;
  myTree.playGame();

  myTree.truncOut();
  myTree.write();
}


