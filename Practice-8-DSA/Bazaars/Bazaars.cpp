#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<queue>
#include<stack>
using namespace std;
void print(map<string, string>Parent, string node)
{
    if (Parent[node] == "START")
    {
        cout << node << " ";
        return;
    }

    print(Parent, Parent[node]);
    cout << node << " ";
}
int main()
{
    int N;
    int M;
    map < string, vector < string>> Graph;
    map<string, bool>Used;
    map<string, string>Parent;
    queue<string>ToVisit;
    string from, to, s;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> from >> to;
        Graph[from].push_back(to);
    }
    cin >> s;
    string node;
    string next;
    ToVisit.push(s);
    Used[s] = 1;
    Parent[s] = "START";
    while (!ToVisit.empty())
    {
        node = ToVisit.front();
        ToVisit.pop();
        for (int i = 0; i < Graph[node].size(); i++)
        {
            next = Graph[node][i];
            if (next == s)
            {
                string res=node;
                stack<string> Ans;
                Ans.push(next);
                while(res!="START")
                {
                    Ans.push(res);
                    res=Parent[res];
                }
                while(!Ans.empty())
                {
                    cout<<Ans.top()<<" ";
                    Ans.pop();
                }
                return 0;
            }
            if (Used[next])continue;
            Used[next] = 1;
            ToVisit.push(next);
            Parent[next] = node;
        }
    }
    cout << -1;
    return 0;
}