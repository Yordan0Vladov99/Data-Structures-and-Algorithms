#include<cstdio>
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int dist[1001][1001],n,m;

void init(){
    int from,to,weight;

    scanf("%d %d",&n,&m);

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            dist[i][j]=INT_MAX;
        }
        dist[i][i]=0;
    }

    for(int i=0;i<m;i++){
        scanf("%d %d %d",&from,&to,&weight);
        dist[from][to]=weight;
    }
}

void floyd(){
    for(int k=1;k<n+1;k++){
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
}



int main(){
    init();
    floyd();
    int Q;
    cin>>Q;
    int from,to;
    vector<int> Gr;
    for(int i=0;i<Q;i++)
    {
       cin>>from>>to;
       if(dist[from][to]==INT_MAX)Gr.push_back(-1);
       else Gr.push_back(dist[from][to]);
        
    }
    for(auto i:Gr)
    {
        cout<<i<<endl;
    }
}