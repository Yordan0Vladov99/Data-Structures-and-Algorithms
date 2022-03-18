#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node
{
    double value;
    Node *left;
    Node *right;

    Node(double value, Node *left, Node *right)
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
        /* compute the depth of each subtree */
        int lDepth = height(node->left);  
        int rDepth = height(node->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
} 


 double getMax(Node* root) {
        Node* current = root;
        while (current->right) {
            current = current->right;
        }
       
        return current->value;
    }
Node* insert(Node* root, double data) {
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
                   cout<<data<<" already added"<<endl;
                   return root;
               }

               return root;
           }
        }
 Node* deleteNode(Node* root, double key) {
        if (root == nullptr) {
            cout<<key<<" not found to remove"<<endl;
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
                double toReplace = getMax(root->left);
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

    bool containsRecursive(Node *current, double value)
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

        printRecursive(current->left);
        cout << current->value << " "<<fixed;
        printRecursive(current->right);
    }

public:
    AVLTree()
    {
        root = NULL;
    }

    void add(double value)
    {
        root=insert(root,value);
    }

    void remove(double value)
    {
        
        root=deleteNode(root,value);
       //if (root == NULL)return;  
       // int balance = getBalance(curr);  
       //   
       // if (balance > 1 &&  
       // getBalance(curr->left) >= 0)  
       // rightRotate(curr);  
  
       
    //    if (balance > 1 &&  
    //    getBalance(curr->left) < 0)  
    //{  
    //    curr->left = leftRotate(curr->left);  
    //    rightRotate(curr);  
    //}  
  //
  //
    //if (balance < -1 &&  
    //    getBalance(curr->right) <= 0)  
    //    leftRotate(curr);  
  //
    //
    //if (balance < -1 &&  
    //    getBalance(curr->right) > 0)  
    //{  
    //    curr->right = rightRotate(curr->right);  
    //    leftRotate(curr);  
    //}  
    //    
    }

bool contains(double value)
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
        cout << endl;
    }
};

int main()
{
    AVLTree tree;
    string operation;
    double number;
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