#include<iostream>
using namespace std;
int main()
{
    int M = 0;
    int N = 0;
    cin >> M >> N;
    if (M <= 1000000 && N <= 1000 && N>=0)
    {
        int* arr = new int[N];
        for (size_t i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        int*BigArr = new int[N];
        int BigSize = 0;
        int*SmallArr = new int[N];
        int SmallSize = 0;
        for (size_t i = 0; i < N; i++)
        {
            if (arr[i] >= M)
            {
                BigArr[BigSize] = arr[i];
                BigSize++;
            }
            else
            {
                SmallArr[SmallSize] = arr[i];
                SmallSize++;
            }
        }
        for (size_t i = 0; i < BigSize; i++)
        {
            for (size_t j = 0; j < SmallSize; j++)
            {
                while (BigArr[i] > M && SmallArr[j] < M)
                {
                    BigArr[i]--;
                    SmallArr[j]++;
                }
            }
        }
        for (size_t i = 0; i < SmallSize; i++)
        {
            if (SmallArr[i] < M)
            {
                cout << "no";
                return 0;
            }
        }
        cout << "yes";
    }
    return 0;
}