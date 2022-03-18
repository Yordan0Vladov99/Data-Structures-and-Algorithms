#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<cmath>
using namespace std;
struct Coordinate
{
    int x;
    int y;
    long long dist;
public:
    Coordinate()
    {
        x = 0;
        y = 0;
        dist = 0;
    }
    friend bool operator<(const Coordinate &a, const Coordinate&b)
    {
        if (a.dist < b.dist)return true;
        else if (a.dist > b.dist)return false;
        else
        {
            if (a.x < b.x)return true;
            else if (a.x > b.x)return false;
            else
            {
                if (a.y < b.y)return true;
                return false;
            }
        }
    }
    friend bool operator>(const Coordinate &a, const Coordinate&b)
    {
        return(b < a);
    }
    friend bool  operator==(const Coordinate &a, const Coordinate &b)
    {
        return(a.x == b.x && a.y == b.y);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N = 0;
    int K = 0;
    cin >> N >> K;
    Coordinate* Nums = new Coordinate[N];
    for (long long i = 0; i < N; i++)
    {
        cin >> Nums[i].x >> Nums[i].y;
        Nums[i].dist = pow(Nums[i].x, 2) + pow(Nums[i].y, 2);
        
    }
    priority_queue<Coordinate> Q;
    for (long long i = 0; i < N; i++)
    {
        Q.push(Nums[i]);
        if (Q.size() > K)
        {
            Q.pop();
        }
    }
    stack<Coordinate> a;
    for (long long i = 0; i < K; i++)
    {
        a.push(Q.top());
        Q.pop();
    }
    for (long long i = 0; i < K; i++)
    {
        cout << a.top().x << " " << a.top().y << endl;
        a.pop();
    }
    return 0;
}
