#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map<int,vector<int>> Graph;

int dsuParent[1000005];
int findRoot(int node)
{
    if (dsuParent[node] == node)return node;

    int root = findRoot(dsuParent[node]);
    dsuParent[node] = root;
    return root;
}


int main()
{
    int sum = 1;
    int finalSum = 1;
    int n, m;
    cin >> n >> m;
    for (int ind = 1; ind < n+1; ind++)
    {
        dsuParent[ind] = ind;
    }
    int root1, root2;
    int from, to;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        

        root1 = findRoot(from);
        root2 = findRoot(to);

        if (root1 != root2)
        {
            Graph[from].push_back(to);
            Graph[to].push_back(from);
            dsuParent[root1] = root2;
        }
    }
    int Q,type;
    cin>>Q;
    string ans;
    for(int i=0;i<Q;i++)
    {
        cin>>type>>from>>to;
        if(type==1)
        {
            if(findRoot(from)==findRoot(to))ans+="1";
            else ans+="0";
        }
        if(type==2)
        {
        root1 = findRoot(from);
        root2 = findRoot(to);

        if (root1 != root2)
        {
            Graph[from].push_back(to);
            Graph[to].push_back(from);
            dsuParent[root1] = root2;
        }
        }
    }
    cout<<ans;
    return 0;
}