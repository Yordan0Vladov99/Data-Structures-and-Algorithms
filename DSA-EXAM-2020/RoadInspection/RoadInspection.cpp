#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin>>N;
    vector<pair<int,int>>Graph[1000];
    int Used[1000];
    int M;
    cin>>M;
    int from,to,weight;
    for(int i=0;i<M;i++)
    {
        cin>>from>>to>>weight;
        Graph[from].push_back({to,weight});
        Graph[to].push_back({from,weight});
    }
    int length=0;
    int K;
    cin>>K;
    cin>>from;
    
    for(int i=0;i<K-1;i++)
    {
        cin>>to;
        bool Found=0;
        for(int j=0;j<Graph[from].size();j++)
        {
            if(to==Graph[from][j].first && to!=from)
            {
                length+=Graph[from][j].second;
                int node=from;
                from=Graph[node][j].first;
                Found=1;
            }
            if(j==Graph[from].size()-1 && !Found)
            {
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<length;
    return 0;
}