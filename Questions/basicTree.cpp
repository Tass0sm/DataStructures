#include <stdio.h>
#include <iostream>
using namespace std;


struct node {
  int data;
  node *left = NULL;
  node *right = NULL;
};

int nodeProcess(node *aNode) {
  cout << "Processed Node" << endl;
  return 0;
}

class tree {

private:
  node *root;
public:
  void create() {
    root = NULL;
  }

  node *getRoot() {
    return root;
  }
  
  bool empty() {
    return root == NULL; 
  }

  void insert(node *current, node newNode) {
    if (current == NULL) {
      root = &newNode;
    } else {
      if (newNode.data == 0) {
	current->left = &newNode;
      } else {
	current->right = &newNode;
	//	(current->right)->left = NULL;
	//	(current->right)->right = NULL;
      }
    }
  }

  void preOrderTraverse(node *current, int process(node*)) {
    current->data = process(current);

    if (current->left != NULL) {
      preOrderTraverse(current->left, process);
    }

    if (current->right != NULL) {
      preOrderTraverse(current->right, process);
    }
  }

  void inOrderTraverse(node *current, int process(node*)) {
    if (current->left != NULL) {
      cout << "Visiting Left" << endl;
      preOrderTraverse(current->left, process);
    }

    cout << "Visiting Center" << endl;
    process(current);

    if (current->right != NULL) {
      cout << "Visiting Right" << endl;
      preOrderTraverse(current->right, process);
    }
  }

  void postOrderTraverse(node *current, int process(node*)) {
    if (current->left != NULL) {
      preOrderTraverse(current->left, process);
    }
    
    if (current->right != NULL) {
      preOrderTraverse(current->right, process);
    }

    current->data = process(current);
  }
};


int main(int argc, char *argv[]) {
  tree myTree;
  myTree.create();
  struct node node1;
  node1.data = 0;

  myTree.insert(myTree.getRoot(), node1);

  struct node node2;
  node2.data = 1;

  myTree.insert(myTree.getRoot(), node2);

  cout << myTree.getRoot()->left << endl;
  cout << myTree.getRoot()->right << endl;
  
  myTree.inOrderTraverse(myTree.getRoot(), nodeProcess);
    
  return 0;
}
