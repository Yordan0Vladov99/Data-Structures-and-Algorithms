#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node
{
    int value;
    Node *left;
    Node *right;

    Node(int value, Node *left, Node *right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }
};
int height(Node* node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        
        int lDepth = height(node->left);  
        int rDepth = height(node->right);  
      
      
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
} 


 int getMax(Node* root) {
        Node* current = root;
        while (current->right) {
            current = current->right;
        }
       
        return current->value;
    }
Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data,NULL,NULL);
            } else {
                Node* cur;
                if(data < root->value) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else if(data>root->value) {
                    cur = insert(root->right, data);
                    root->right = cur;
               }
               else
               {
                   return root;
               }

               return root;
           }
        }
 Node* deleteNode(Node* root, int key) {
        if (root == nullptr) {
            return root;
        }
       
        if (key < root->value) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->value) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                Node* toReturn = root->right;
                delete root;
                return toReturn;
            } else if (root->right == nullptr) {
                Node* toReturn = root->left;
                delete root;
                return toReturn;
            } else {
                int toReplace = getMax(root->left);
                root->value = toReplace;
                root->left = deleteNode(root->left, toReplace);
            }
        }
       
        return root;
    }
class AVLTree
{
private:
    Node *root;

    bool containsRecursive(Node *current, int value)
    {
        if (current == NULL)
        {
            return false;
        }

        if (current->value == value)
        {
            return true;
        }

        if (value < current->value)
        {
            return containsRecursive(current->left, value);
        }
        else
        {
            return containsRecursive(current->right, value);
        }
    }

    void printRecursive(Node *current)
    {
        if (current == NULL)
        {
            return;
        }

        cout << current->value << " ";
        printRecursive(current->left);
        printRecursive(current->right);
    }

public:
    AVLTree()
    {
        root = NULL;
    }

    void add(int value)
    {
        root=insert(root,value);
    }

    void remove(int value)
    {
        root=deleteNode(root,value);
      
    }

bool contains(int value)
    {
        if (root == NULL)
        {
            return false;
        }

        return containsRecursive(root, value);
    }

    void print()
    {
        if (root == NULL)
        {
            return;
        }

        printRecursive(root);
    }
};

int main()
{
    AVLTree tree;
    string operation;
    int number;
    int N;

    cin >> N;
    cout << fixed;

    for (size_t i = 0; i < N; i++)
    {
        cin >> operation;
        if (operation != "print")
        {
            cin >> number;
        }

        if (operation == "add")
        {
            tree.add(number);
        }
        else if (operation == "remove")
        {
            tree.remove(number);
        }
        else if (operation == "contains")
        {
            if (tree.contains(number))
            {
                cout << "yes" << endl;
            }
            else
            {
                cout << "no" << endl;
            }
        }
        else if (operation == "print")
        {
            tree.print();
        }
    }
    return 0;
}