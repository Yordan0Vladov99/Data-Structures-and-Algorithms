#include<iostream>
using namespace std;
struct Node
{
    int key;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->key = val;
        this->left = NULL;
        this -> right = NULL;
    }
    
};
Node* insert(Node*root, long long val)
{

    if (root == NULL)
    {
        return new Node(val);
    }
    if (val < root->key)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->key)
    {
        root->right = insert(root->right, val);
    }
    return root;
}
long long dist(Node* root, long long val,long long counter)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->key == val)
    {
        return counter;
    }
    if (val < root->key)
    {
        counter++;
        return dist(root->left, val,counter);
    }
    else if (val > root->key)
    {
        counter++;
        return dist(root->right, val,counter);
    }
    return -1;
}
int main()
{
    Node* tree=NULL;
    long long N;
    cin >> N;
    long long K;
    cin >> K;
    long long def = 0;
    for (long long i = 0; i < N; i++)
    {
        cin >> def;
        tree = insert(tree, def);
    }
    long long*arr = new long long[K];
    for (long long i = 0; i < K; i++)
    {
        cin >> arr[i];
    }
    for (long long i = 0; i < K; i++)
    {
        cout << dist(tree, arr[i], 0) << endl;
    }
    return 0;
}
