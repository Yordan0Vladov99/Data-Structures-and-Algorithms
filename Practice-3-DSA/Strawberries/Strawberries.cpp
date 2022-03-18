#include<iostream>
#include<vector>
using namespace std;


int BinarySearch(long long arr[], int l, int h, long long x)
{
    if (l <= h)
    {
        int m = l + (h - l) / 2;
        if (x <= arr[l])return l+1;
        if (x <= arr[m] && x > arr[m - 1])return m+1;
        else if (x < arr[m])return BinarySearch(arr, l, m-1, x);
        else return BinarySearch(arr, m + 1, h, x);
    }
    return -1;

}
int main()
{
    int N = 0;
    cin >> N;
    long long* Strawberries = new long long[N];
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        int s = 0;
        cin >> s;
        sum += s;
        Strawberries[i]=0;
        Strawberries[i]+= sum;
        
    }
    int M = 0;
    cin >> M;
    long long* TastyStrawberries=new long long[M];
    for (int i = 0; i < M; i++)
    {
        cin >> TastyStrawberries[i];
    }
    for (size_t i = 0; i < M; i++)
    {
        cout << BinarySearch(Strawberries, 0, N - 1, TastyStrawberries[i]) << endl;
    }
    
    return 0;
}