#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<queue>
using namespace std;
int main()
{
    int N;
    int M;
    cin >> N >> M;
    int from, to, counter = 0;
    unordered_map<int, vector<int>> Graph;
    unordered_map<int, bool>Used;
    counter = 0;
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> from >> to;
        Graph[from].push_back(to);
        Graph[to].push_back(from);
    }
    queue<int>ToVisit;
    for (auto i:Graph)
    {
        if (Used[i.first])continue;
        ans++;
        ToVisit.push(i.first);
        Used[i.first] = 1;
        int node;
        int next;
        while (!ToVisit.empty())
        {
            node = ToVisit.front();
            counter++;
            ToVisit.pop();
            for (int j = 0; j < Graph[node].size(); j++)
            {
                next = Graph[node][j];
                if (Used[next])continue;
                ToVisit.push(next);
                Used[next] = 1;
            }
        }
    }
    cout <<ans+N-counter;
    return 0;
}