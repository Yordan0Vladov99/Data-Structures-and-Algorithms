#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
    int N = 0;
    cin >> N;
    int K = 0;
    cin >> K;
    int* arr = new int[N];
    int* arr2 = new int[N];
    int*arr3 = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        arr2[arr[i] - 1] = i;
        arr3[i] = 0;
    }
    int counter = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (arr[arr2[i]] != 0)
        {
            if (counter == 0)
            {
                arr3[arr2[i]] = 1;
            }
            else arr3[arr2[i]] = 2;
            arr[arr2[i]] = 0;
        
            int l = arr2[i]-1;
            int r = arr2[i]+1;
            int x = 0;
            while (x != K && l >= 0)
            {
                if (arr[l] != 0)
                {
                    if (counter == 0)
                    {
                        arr3[l] = 1;
                    }
                    else arr3[l] = 2;
                    arr[l] = 0;
                    x++;
                }
                l--;
            }
            x = 0;
            while (x != K && r < N)
            {
                if (arr[r] != 0)
                {
                    if (counter == 0)
                    {
                        arr3[r] = 1;
                    }
                    else arr3[r] = 2;
                    arr[r] = 0;
                    x++;
                }
                r++;
            }
            if (counter == 0)counter = 1;
            else counter = 0;
        }
    }
    for (int i = 0; i < N; i++)
    {
        cout << arr3[i];
    }

    return 0;
}