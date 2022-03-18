#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<set>
using namespace std;
struct Directory
{
    Directory* parent;
    string name;
    map<string, Directory*> Children;
    bool insert(string str)
    {
        if (Children.find(str) != Children.end())
        {
            return false;
        }
        else
        {
            Children[str] = new Directory;
            Children[str]->parent = this;
            Children[str]->name = str;
        }
        return true;
    }
    string print()
    {
        string b = "";
        for (auto itr : Children)
        {
            b += itr.first + " ";
        }
        b += "\n";
        return b;
    }
    void helppath(Directory* n, string &str)
    {
        if (n->parent == NULL)
        {
            str += "/";
            return;
        }
        helppath(n->parent, str);
        str += n->name + "/";
        return;
    }
    string path()
    {
        string a = "";
        helppath(this, a);
        return a + "\n";
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string Words;
    string a;
    string b;
    Directory *Dir = new Directory;
    Dir->name = "/";
    Dir->parent = NULL;
    for (int i = 0; i < N; i++)
    {
        cin >> a;
        if (a == "mkdir")
        {
            cin >> b;
            if (!Dir->insert(b))
            {
                Words += "Directory already exists\n";
            }
        }
        if (a == "ls")
        {

            Words += Dir->print();
        }
        if (a == "pwd")
        {
            if (Dir->name == "/")
            {
                Words += "/\n";
            }
            else Words += Dir->path();
        }
        if (a == "cd")
        {
            cin >> b;
            if (b == "..")
            {
                if (Dir->parent == NULL)
                {
                    Words += "No such directory\n";
                }
                else
                {
                    Dir = Dir->parent;
                }
            }
            else if (Dir->Children.find(b) == Dir->Children.end())
            {
                Words += "No such directory\n";
            }
            else
            {
                Dir = Dir->Children[b];
            }
        }
    }
    cout << Words;

    return 0;
}