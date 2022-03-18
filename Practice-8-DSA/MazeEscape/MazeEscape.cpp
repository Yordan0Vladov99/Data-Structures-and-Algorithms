#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<queue>
#include<climits>
using namespace std;
#define pi pair<int,int> 
int main()
{
    int N;
    int M;
    cin >> N >> M;
    char** Grid = new char*[1001];
    bool** Used = new bool*[1001];
    for (int i = 0; i < 1001; i++)
    {
        Grid[i] = new char[1001];
        Used[i] = new bool[1001];
    }
    pi S;
    pi F;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Grid[i][j];
            if (Grid[i][j] == 'S')S = { i,j };
            if (Grid[i][j] == 'F')F = { i,j };
            Used[i][j] = 0;
        }
        //Grid[i][N] = 0;
    }
    queue<pi>ToVisit;
    int level = 0;
    int NodesOnLevel = 1;
    pi node;
    ToVisit.push(S);
    Used[S.first][S.second] = 1;
    while (!ToVisit.empty())
    {
        node = ToVisit.front();
        if (node == F)
        {
            cout << level;
            return 0;
        }
        ToVisit.pop();
        NodesOnLevel--;
        int k = node.first - 1;
        int m = node.second;
        while (k >= 0 && Grid[k][m] != '#')k--;
            
        k++;
        if (!Used[k][m])
           {
            ToVisit.push({ k,m });
            Used[k][m] = 1;
            }
        k = node.first;
        m = node.second;
        while (m >= 0 && Grid[k][m] != '#')m--;
            
        m++;
        if (!Used[k][m])
        {
            ToVisit.push({ k,m });
            Used[k][m] = 1;
        }
        k = node.first + 1;
        m = node.second;
        while (k < N && Grid[k][m] != '#')k++;
            
        k--;
        if (!Used[k][m])
        {
            ToVisit.push({ k,m });
            Used[k][m] = 1;
        }
        k = node.first;
        m = node.second + 1;
        while (m < M && Grid[k][m] != '#')m++;
            
        m--;
        if (!Used[k][m])
        {
            ToVisit.push({ k,m });
            Used[k][m] = 1;
        }
        if (node.first >= 1 && Grid[node.first - 1][node.second] != '#' && !Used[node.first - 1][node.second])
        {
            ToVisit.push({ node.first - 1,node.second });
            Used[node.first - 1][node.second] = 1;
            
        }
        if (node.second >= 1 && Grid[node.first][node.second - 1] != '#' && !Used[node.first][node.second - 1])
        {
            ToVisit.push({ node.first,node.second - 1 });
            Used[node.first][node.second - 1] = 1;
        }
        if (node.first < N - 1 && Grid[node.first + 1][node.second] != '#' && !Used[node.first + 1][node.second])
        {
            ToVisit.push({ node.first + 1,node.second });
            Used[node.first + 1][node.second] = 1;
        }
        if (node.second < M - 1 && Grid[node.first][node.second + 1] != '#' && !Used[node.first][node.second + 1])
        {
            ToVisit.push({ node.first,node.second + 1 });
            Used[node.first][node.second + 1]=1;
        }
        if (NodesOnLevel == 0)
        {
            level++;
            NodesOnLevel = ToVisit.size();
        }
    }
    cout << -1;
    return 0;
}
