#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<queue>
#include<climits>
using namespace std;
vector<int> Dijkstra(vector<pair<int, int>>Graph[], int s,int n)
{
    int used[100001];
    vector<int> dist;
    for (int i = 0; i < n; i++)
    {
        used[i] = 0;
        dist.push_back(INT_MAX);
    }
    int node;
    pair<int, int> edge;
    priority_queue < pair<int, int>, vector < pair<int, int>>, greater<pair<int,int>>>ToVisit;
    ToVisit.push({ 0,s });
    dist[s] = 0;
    while (!ToVisit.empty())
    {
        node = ToVisit.top().second;
        ToVisit.pop();
        if (used[node])continue;
        used[node] = 1;
        for (int i = 0; i < Graph[node].size(); i++)
        {
            edge = Graph[node][i];
            if (dist[node] + edge.second < dist[edge.first])
            {
                dist[edge.first] = dist[node] + edge.second;
                ToVisit.push({ dist[edge.first],edge.first });
            }
        }
    }
    return dist;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int M;
    cin >> N >> M;
    vector<pair<int, int>>*Graph=new vector < pair<int, int>>[N+1];
    int from, to, weight;
    for (size_t i = 0; i < M; i++)
    {
        cin >> from >> to >> weight;
        Graph[from].push_back({ to,weight});
        Graph[to].push_back({from,weight});
    }
    int K;
    cin >> K;
    int k;
    for (int i = 0; i < K; i++)
    {
        cin>>k;
        Graph[N].push_back({k,0});
        Graph[k].push_back({N,0});
    }
    int Q;
    cin >> Q;
    int* callers = new int[Q];
    for (int i = 0; i < Q; i++)
    {
        cin >> callers[i];
    }
    vector<int>dist=Dijkstra(Graph,N,N+1);
    for (int i = 0; i < Q; i++)
    {
        cout <<  dist[callers[i]] << endl;
    }
    return 0;
}