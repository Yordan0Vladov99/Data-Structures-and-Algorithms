#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include<map>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    int* arr=new int[N];
    map<int,pair<int,int>> S;
    cin>>arr[0];
    int num=arr[0];
    S[arr[0]].first=0;
    for(int i=1;i<N;i++)
    {
        cin>>arr[i];
        if(num!=arr[i])
        {
            S[num].second=i-1;
            num=arr[i];
            S[num].first=i;
        }
        if(i==N-1 && num==arr[i])S[num].second=i;
    }
    vector<pair<int,int>>ans;
    int Q;
    cin>>Q;
    int a;
    int pos;
    for(int i=0;i<Q;i++)
    {
    cin>>a;
    if(S.find(a)!=S.end())
    {
    
    ans.push_back({S[a].first,S[a].second});   
     
    }    
    else
    {
    if(a<arr[0])pos=0;
    else if(a>arr[N-1])pos=N;
    else{
    int l = 0;
    int r = N - 1;
    while (r >= l)
    {
        int mid = l + (r-l) / 2;
        if (a == arr[mid]){
            pos = mid;
        }
        if (a < arr[mid]){
            r = mid - 1;
            pos = mid;
        }
        else{
            l = mid + 1;
            pos = mid + 1;
        }
        
    }   
    }
    ans.push_back({pos,-1});
    }
}
     for(int i=0;i<Q;i++)
    {
        cout<<ans[i].first;
        if(ans[i].second!=-1)cout<<" "<<ans[i].second;
        cout<<endl;
    }
    return 0;
}