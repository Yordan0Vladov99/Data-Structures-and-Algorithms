#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;


bool isFeasible(long long arr[], int mid, int n, int k)
{
    long long pos = arr[0];
    long long elements = 1;
    for (size_t i = 0; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            elements++;
            pos = arr[i];
        }
        if (elements == k)
        {
            return true;
        }
    }
    return false;

}
long long MinDistance(long long arr[], int n, int k)
{
    sort(arr, arr + n);
    long long res = -1;
    long long l = arr[0]; long long r = arr[n - 1];
    while (l < r)
    {
        long long m = (l + r) / 2;
        if (isFeasible(arr, m, n, k))
        {
            res = max(res, m);
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    return res;
}
int main()
{
    long long N = 0;
    cin >> N;
    long long Cows = 0;
    cin >> Cows;
    long long* Huts = new long long[N];
    for (int i = 0; i < N; i++)
    {
        cin >> Huts[i];
    }
    cout << MinDistance(Huts, N, Cows);

    return 0;
}