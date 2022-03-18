#include<iostream>
#include<string>
using namespace std;


struct TrieNode
{
    TrieNode* children[26];
    int ChildrenCount;
    bool isEnd;
};
TrieNode* GetNode()
{
    TrieNode *pNode = new TrieNode;
    pNode->isEnd = false;
    for (int i = 0; i < 26; i++)
    {
        pNode->children[i] = NULL;
        pNode->ChildrenCount = 0;
    }
    return pNode;
}
void insert(TrieNode* root, string s)
{
    TrieNode *pCrawl = root;
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        if (!pCrawl->children[index]){pCrawl->children[index] = GetNode();}
        pCrawl->ChildrenCount++;
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEnd = true;
}
bool search(TrieNode* root, string s)
{
    TrieNode *pCrawl = root;
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        if (!pCrawl->children[index])return false;
        pCrawl = pCrawl->children[index];
    }
    return(pCrawl != NULL && pCrawl->isEnd);
}
int prefix(TrieNode* root, string s)
{
    TrieNode *pCrawl = root;
    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a';
        if (!pCrawl->children[index])return 0;
        pCrawl = pCrawl->children[index];
    }
    int k= pCrawl->ChildrenCount;
    if (search(root, s))
    {
        k++;
    }
    return k;
}

int main()
{
    int N;
    int K;
    cin >> N;
    cin >> K;
    string a;
    TrieNode* root = GetNode();
    int* arr = new int[K];
    for (size_t i = 0; i < N; i++)
    {
        cin >> a;
        insert(root, a);
    }
    for (int i = 0; i < K; i++)
    {
        cin >> a;
        arr[i] = prefix(root, a);
    }
    for (size_t i = 0; i < K; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}