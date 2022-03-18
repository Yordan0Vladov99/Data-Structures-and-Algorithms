#include<iostream> 
#include<vector>
#include<queue>
#include<stdio.h>
using namespace std;

#define MAXN 100001

 
vector<long long> v[MAXN];

 
void add_edge(long long a, long long b, long long fre[])
{
    v[a].push_back(b);
    fre[b]++;
}

vector<long long> topological_sorting(long long fre[], long long n)
{
    queue<int> q;

    for (int i = 0; i < n; i++)
        if (!fre[i])
            q.push(i);

    vector<long long> l;


    while (!q.empty()) {
        int u = q.front();
        q.pop();

      
        l.push_back(u);

    
        for (int i = 0; i < v[u].size(); i++) {
            fre[v[u][i]]--;

        
            if (!fre[v[u][i]])
                q.push(v[u][i]);
        }
    }
    return l;
}

long long numberofPaths(long long source, long long destination, long long n, long long fre[])
{

   
    vector<long long> s = topological_sorting(fre, n);

     
    long long* dp=new long long[n];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 0;
    }
   
    dp[destination] = 1;


    for (long long i = s.size() - 1; i >= 0; i--) {
        for (long long j = 0; j < v[s[i]].size(); j++) {
            dp[s[i]] += dp[v[s[i]][j]];
            dp[s[i]]%=1000000007;
        }
    }

    return dp[source];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long N, M;
    cin >> N >> M;
    long long from, to;
    long long* fre=new long long[N];
    for(int i=0;i<N;i++)
    {
        fre[i]=0;
    }
    for (long long i = 0; i < M; i++)
    {
        cin >> from >> to;
        add_edge(from-1, to-1,fre);
    }

    long long s, d;
    cin >> s >> d;
    cout << numberofPaths(s - 1, d - 1, N, fre);

    return 0;
}
