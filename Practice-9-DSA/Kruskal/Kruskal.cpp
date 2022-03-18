#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct edge{
  int from,to,weight;

  bool operator < (const edge &target)const{
    return this->weight < target.weight;
  }
}edges[100000];

int dsuParent[20000],n,m;
vector<pair<int,int> >mst[20000];

void init(){
    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++){
        scanf("%d %d %d",&edges[i].from,&edges[i].to,&edges[i].weight);
    }
}

int findRoot(int node){
    if(dsuParent[node]==node)return node;///if the node is its own parent then it is the root of the tree

    int root = findRoot(dsuParent[node]);///finding the root
    dsuParent[node]=root;///making this node's parent the root. This way next time we want the root of node it will be faster to find

    return root;
}

void makeMST(){
    int root1,root2;

    sort(edges,edges+m);
    for(int ind=0;ind<n;ind++){
        dsuParent[ind]=ind;
    }
    int weight=0;
    for(int ind=0;ind<m;ind++){///for each edge
        ///get the roots of both ends of the edge
        root1=findRoot(edges[ind].from);
        root2=findRoot(edges[ind].to);

        if(root1!=root2){
            
            mst[edges[ind].from].push_back({edges[ind].to,edges[ind].weight});
            mst[edges[ind].to].push_back({edges[ind].from,edges[ind].weight});
            dsuParent[root1]=root2;
            weight+=edges[ind].weight;
        }
    }
    cout<<weight;
}

int main(){
    init();
    makeMST();
}