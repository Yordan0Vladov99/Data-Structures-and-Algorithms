#include <bits/stdc++.h>

using namespace std;


int components(vector<int> Gr[],int n) {
    
    bool used[100001];
   
    
    for(int i=0;i<100001;i++)
    {
        used[i]=0;
    }
    queue<int>ToVisit;
    int counter=0;
    int max=0;
    int min=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(used[i])continue;
        ToVisit.push(i);
        used[i]=1;
        int node;
        int next;
         while(!ToVisit.empty()){
        node=ToVisit.front();
        ToVisit.pop();

        for(int i=0;i<Gr[node].size();i++){
            next=Gr[node][i];

            if(used[next]==1)continue;

            ToVisit.push(next);
            used[next]=1;
        }
    }
        
        counter++;
    }
    return counter;

}

int main()
{
    int Q;
    cin>>Q;
    vector<int> ans;
    for(int n=0;n<Q;n++)
    {
        int N,M;
        cin>>N>>M;
        int from,to;
        vector<int>Gr[100000];
        for(int i=0;i<M;i++)
        {
        cin>>from>>to;
        Gr[from].push_back(to);
        Gr[to].push_back(from);
        }
        int res=components(Gr,N);
        ans.push_back(res);
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}