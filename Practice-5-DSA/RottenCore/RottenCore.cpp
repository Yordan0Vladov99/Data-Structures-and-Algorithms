#include<iostream>
#include<queue>
using namespace std;



int main()
{
    long long R;
    long long C;
    long long T;
    cin >> R >> C >> T;

    bool**arr = new bool*[R];
    for (long long i = 0; i < R; i++)
    {
        arr[i] = new bool[C];
    }
    for (long long i = 0; i < R; i++)
    {
        for (long long  j = 0; j < C; j++)
        {
            arr[i][j] = 0;
        }
    }
    long long l[2] = { -1,-1 };
    long long r[2] = { -1,-1 };
    int i = 0;
    while (i<2 && cin >> l[i] >> r[i])
    {
        i++;
    }
    queue<pair<long long, long long>> ToVisit;
    pair<long long ,long long> start1;
    start1.first = R-l[0]; start1.second = r[0]-1;
    pair<long, long> start2;
    ToVisit.push(start1);
    arr[start1.first][start1.second] = 1;
    long long counter1 = 1;
    long long rottensum = 0;
    rottensum += counter1;
    if (l[1] != -1 && r[1] != -1)
    {
        start2.first = R - l[1]; start2.second = r[1] - 1;
        ToVisit.push(start2);
        arr[start2.first][start2.second] = 1;
        counter1++;
        rottensum ++;
    }
    
    for (size_t i = 0; i < T; i++)
    {
        
        long long tempcounter1 = counter1;
        counter1 = 0;
        while (tempcounter1 > 0)
        {
            pair<long long, long long>temp = ToVisit.front();
            ToVisit.pop();
            temp.first += 1;
            if (temp.first >= 0 && temp.first < R && arr[temp.first][temp.second] == 0)
            {
                arr[temp.first][temp.second] = true;
                ToVisit.push(temp);
                counter1++;
            }
            temp.first -= 2;
            if (temp.first >= 0 && temp.first < R && arr[temp.first][temp.second] == 0)
            {
                arr[temp.first][temp.second] = true;
                ToVisit.push(temp);
                counter1++;
            }
            temp.first += 1;
            temp.second += 1;
            if (temp.second >= 0 && temp.second < C && arr[temp.first][temp.second] == 0)
            {
                arr[temp.first][temp.second] = true;
                ToVisit.push(temp);
                counter1++;
            }
            temp.second -= 2;
            if (temp.second >= 0 && temp.second < C && arr[temp.first][temp.second] == 0)
            {
                arr[temp.first][temp.second] = true;
                ToVisit.push(temp);
                counter1++;
            }
            temp.second += 1;
            tempcounter1--;
        }
        rottensum += counter1;
    }


    cout << R * C - rottensum;
    return 0;
}
