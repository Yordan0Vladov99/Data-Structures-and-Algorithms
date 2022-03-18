#include<iostream>
using namespace std;
long long counter = 0;
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int* L = new int[n1];
    int* R = new int[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            counter += n1 - i;
        }
        k++;
    }

    
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{

    if (l < r)
    {
        
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N = 0;
    cin >> N;
    if (N <= 100000)
    {
        int*arr = new int[N];
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        mergeSort(arr, 0, N - 1);
        cout << counter;
    }
    return 0;
}