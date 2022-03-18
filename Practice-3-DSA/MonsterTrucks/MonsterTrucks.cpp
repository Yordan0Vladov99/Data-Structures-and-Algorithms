#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<math.h>
using namespace std;


void merge(long long arr[], long long l, long long m, long long r, long long arr2[])
{
    long long i, j, k;
    long long n1 = m - l + 1;
    long long n2 = r - m;

    long long* L = new long long[n1];
    long long* R = new long long[n2];
    long long* L2 = new long long[n1];
    long long* R2 = new long long[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
        L2[i] = arr2[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
        R2[j] = arr2[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            arr2[k] = L2[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            arr2[k] = R2[j];
            j++;
        }
        k++;
    }


    while (i < n1)
    {
        arr[k] = L[i];
        arr2[k] = L2[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        arr2[k] = R2[j];
        j++;
        k++;
    }
}
void mergeSort(long long arr[], long long l, long long r, long long arr2[])
{

    if (l < r)
    {

        long long m = l + (r - l) / 2;
        mergeSort(arr, l, m, arr2);
        mergeSort(arr, m + 1, r, arr2);

        merge(arr, l, m, r, arr2);
    }
}
int main()
{
    long long N = 0;
    cin >> N;
    long long* Trucks = new long long[N];
    long long* Redbulls = new long long[N];
    for (long long i = 0; i < N; i++)
    {
        cin >> Trucks[i] >> Redbulls[i];
    }
    mergeSort(Trucks, 0, N - 1, Redbulls);
    long long l = Trucks[0];
    long long r = Trucks[N - 1];
    long long res = 0;
    bool FirstCycle = true;
    while (l <= r)
    {
        long long m1 = floor(l + (r - l) / 3);
        long long m2 = ceil(r - (r - l) / 3);
        long long sum1 = 0;
        long long sum2 = 0;
        for (long long i = 0; i < N; i++)
        {
            sum1 += abs((m1 - Trucks[i])*Redbulls[i]);
            sum2 += abs((m2 - Trucks[i])*Redbulls[i]);
        }
        if (sum1 == sum2)
        {
            l = m1 + 1;
            r = m2 - 1;
            if (FirstCycle)
            {
                res = sum1;
                FirstCycle = false;
            }
            res = min(res, sum1);
        }
        else if (sum1 < sum2)
        {
            r = m2 - 1;
            if (FirstCycle)
            {
                res = sum1;
                FirstCycle = false;
            }
            res = min(res, sum1);
        }
        else
        {
            if (FirstCycle)
            {
                res = sum2;
                FirstCycle = false;
            }
            l = m1 + 1;
            res = min(res, sum2);
        }
        
    }
    cout << res;
    return 0;
}