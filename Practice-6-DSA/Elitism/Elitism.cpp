#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;


int main()
{

    priority_queue<int> MaxHeap;//small numbers
    priority_queue<int, vector<int>, greater<int>> MinHeap;//large numbers
    double Median;
    int N;
    scanf("%d",&N);
    double a;
    if (N == 0)
    {
        printf("0.0");
        return 0;
    }
    int* arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&arr[i]);
    }
    MaxHeap.push(arr[0]);
    Median = arr[0];
    printf("%d.0\n", arr[0]);
    for (int i = 1; i < N; i++)
    {
        if (arr[i] < Median)
        {
            MaxHeap.push(arr[i]);
        }
        else(MinHeap.push(arr[i]));
        if (abs(MinHeap.size() - MaxHeap.size() >= 2))
        {
            if (MinHeap.size() > MaxHeap.size())
            {
                a = MinHeap.top();
                MinHeap.pop();
                MaxHeap.push(a);
            }
            else
            {
                a = MaxHeap.top();
                MaxHeap.pop();
                MinHeap.push(a);
            }
        }
        if (MinHeap.size() > MaxHeap.size())
        {
            printf("%d.0\n", MinHeap.top());
            Median = MinHeap.top();
        }
        else if (MaxHeap.size() > MinHeap.size())
        {
            printf("%d.0\n", MaxHeap.top());
            Median = MaxHeap.top();
        }
        else
        {

            a = MinHeap.top() + MaxHeap.top();
            a /= 2;
            printf("%.1f\n", a);
            Median = a;
        }
    }
    return 0;
}