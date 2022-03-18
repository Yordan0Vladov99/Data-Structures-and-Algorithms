#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<queue>
#include<climits>
#include<algorithm>
#include<climits>
using namespace std;
#define pi pair<int,int>
#define tri pair<int,pi>
int Dijkstra(vector<tri>Graph[], int s,int d, int n,int weight)
{
    int used[100001];
    vector<int> dist;
    for (int i = 0; i < n+1; i++)
    {
        used[i] = 0;
        dist.push_back(INT_MAX);
    }
    int node;
    tri edge;
    priority_queue <tri, vector <tri>, greater<tri>>ToVisit;
    ToVisit.push({ 0,{s,0} });
    dist[s] = 0;
    while (!ToVisit.empty())
    {
        
        node = ToVisit.top().second.first;
        ToVisit.pop();
        if (used[node])continue;
        used[node] = 1;
        for (int i = 0; i < Graph[node].size(); i++)
        {
            edge = Graph[node][i];
            if (edge.second.second > weight)continue;
            if (dist[node] + edge.second.first < dist[edge.first])
            {
                dist[edge.first] = dist[node] + edge.second.first;
                ToVisit.push({ dist[edge.first],{edge.first,edge.second.second} });
            }
        }
    }
    return dist[d];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int M;
    int K;
    cin >> N >> M>>K;
    vector<tri>*Graph = new vector <tri>[N + 1];
    int from, to, weight, lenght;
    int MIN = INT_MAX;
    int MAX = 0;
    int MID = 0;
    int m = 0;
    int ans = INT_MAX;
    for (size_t i = 0; i < M; i++)
    {
        cin >> from >> to >> weight >> lenght;
        Graph[from].push_back({ to,{lenght,weight}});
        if (MIN > weight)MIN = weight;
        if (MAX < weight)MAX = weight;
    }
    while (MIN <= MAX)
    {
        MID = MIN + (MAX - MIN) / 2;
        int m = Dijkstra(Graph, 1, N, N, MID);
        if (m > K)
        {
            MIN = MID + 1;
        }
        else
        {
            MAX = MID - 1;
            ans = min(ans, MID);
        }
    }
    if (ans == INT_MAX)cout << -1;
    else cout << ans;
    return 0;
}
