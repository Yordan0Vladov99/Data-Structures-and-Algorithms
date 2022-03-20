#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool isCyclicUtil(int v, bool visited[], bool *recStack, vector<int>Graph[])
{
    if (!visited[v])
    {
        visited[v] = true;
        recStack[v] = true;
        for (int i = 0; i < Graph[v].size(); i++)
        {
            if (!visited[Graph[v][i]] && isCyclicUtil(Graph[v][i], visited, recStack, Graph))
            {
                return true;
            }
            else if (recStack[Graph[v][i]])
            {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}
bool isCyclical(int n, vector<int>Graph[])
{
    bool* visited=new bool[n];
    bool* recStack=new bool[n];
    for (int i = 0; i < n+1; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for (int i = 1; i < n; i++)
    {
        if (isCyclicUtil(i, visited, recStack, Graph))
        {
            return true;
        }
    }

    return false;
}
int main() {
    int Q;
    cin >> Q;
    string ans;
    for (int d = 0; d < Q; d++)
    {
        int V;
        int E;
        int weight;
        cin >> V >> E;
        vector<int> Gr[10001];
        int to, from;
        for (int i = 0; i < E; i++)
        {
            cin >> from >> to>>weight;
            Gr[from].push_back(to);
        }
        if (isCyclical(V, Gr))ans += "true ";
        else ans += "false ";
    }
    cout << ans;
    return 0;
}