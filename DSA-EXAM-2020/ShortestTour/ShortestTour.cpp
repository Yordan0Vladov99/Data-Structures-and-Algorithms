#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;



int bfs(vector<int>* gr,bool* path,int n, int start, int dest)
{
    queue<int> q;
    q.push(start);
    //used[path[0]] = true;
    
    
    int nodesOnLevel =1;
    int level =0;   
    
    
    while (!q.empty()) 
    {
        int v = q.front();
        q.pop();
        nodesOnLevel--;
        if(v == dest){
            return level;
        }
      
        for (int u : gr[v]) 
        {   
            if(!path[u])continue;
            q.push(u);        
        }
        if(nodesOnLevel==0)
        {
            nodesOnLevel = q.size();
            level++;
        }
    }
    return -1;
}
int main()
{
    bool* path;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    scanf("%d %d",&n,&m);
    path = new bool[n];
    vector<int>* gr = new vector<int>[n];
    vector<int> destinations;
    for(int i =0; i<n;i++){
        path[i] = true;
    }
    for(int i =0;i<m;i++)
    {
        int f,t;
        scanf("%d %d",&f,&t);
        gr[f].push_back(t);
    }
    int k;
    scanf("%d",&k);
    for(int i =0;i<k;i++)
    {
        int num;
            scanf("%d",&num);
        destinations.push_back(num);
        path[num] = false;
    }
    
    
    int counter = 0;
    int start = 0;
    for(size_t i = 0; i < destinations.size(); i++){
        if(i == 0){
            start = destinations[i];
            path[start] = true;
        }
        else{
            int destination = destinations[i];
            path[destination] = true;
            int distance = bfs(gr,path,n,start,destination);
            
            if(distance == -1){
                counter = distance;
                break;
            }
            counter+=distance;
            start = destination;
        }
    }
    
    printf("%d",counter);
    return 0;
}