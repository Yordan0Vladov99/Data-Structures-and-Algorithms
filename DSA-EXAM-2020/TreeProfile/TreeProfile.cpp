#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int levelL = 0;
int levelR = 0;
vector<int> ans;

struct Node {
    Node *left;
    Node *right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printLeftProfile() 
    { 
        int maxLvl = 0; 
        PrintL(root, 1, &maxLvl); 
    } 

private:
    
    void PrintL(Node* root, int lvl, int* maxLv) 
    {   
        if (root != NULL) 
        {
        if (*maxLv < lvl) 
        { 
            cout << root->value << " "; 
            *maxLv = lvl; 
        } 
 
            PrintL(root->left, lvl + 1, maxLv); 
            PrintL(root->right, lvl + 1, maxLv); 
        }
    }     
    
      //you can write helper functions if needed
    Node* root;

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
    tree.printLeftProfile();
    return 0;
}
