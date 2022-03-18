#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
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

        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, arr2);
        mergeSort(arr, m + 1, r, arr2);

        merge(arr, l, m, r, arr2);
    }
}
int main()
{

    long long Days = 0;
    cin >> Days;
    long long*ExpectedBalloons = new long long[Days];
    long long Balloons = 0;
    cin >> Balloons;
    long long*Bonbons = new long long[Days];
    long long*DaySum = new long long[Days];
    for (size_t i = 0; i < Days; i++)
    {
        cin >> ExpectedBalloons[i];
    }
    for (size_t i = 0; i < Days; i++)
    {
        cin >> Bonbons[i];
        DaySum[i] = ExpectedBalloons[i] * Bonbons[i];
    }
    long long sum = 0;
    for (size_t i = 0; i < Days; i++)
    {
        sum += ExpectedBalloons[i];
    }
    if (Balloons >= sum)
    {
        cout << 0;
        return 0;
    }
    mergeSort(DaySum,0,Days-1,Bonbons);
    long long l = DaySum[0];
    long long r = DaySum[Days-1];
    long long res = DaySum[Days - 1];
    while (r >= l)
    {
        
        long long L = (l+r)/ 2;
        long long elements = 0;
        for (size_t i = 0; i < Days; i++)
        {
            
            if (DaySum[i] > L && Bonbons[i]!=0)
            {
                elements += (DaySum[i]-L+Bonbons[i]-1)/Bonbons[i];
            }
            
        }
        if (elements > Balloons)
        {
            
            l = L+1;
        }
        else if (elements <= Balloons)
        {
            res = min(res, L);
            r = L-1;
        }
    }
    cout << res;
    return 0;
}