#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int r, int arr2[])
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];
    int* L2 = new int[n1];
    int* R2 = new int[n2];
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
void mergeSort(int arr[], int l, int r, int arr2[])
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
    int N = 0;
    cin >> N;
    int*arr1 = new int[N];
    int*arr2 = new int[N];
    for (size_t i = 0; i < N; i++)
    {
        cin >> arr1[i];
        cin >> arr2[i];
    }
    mergeSort(arr1, 0, N - 1, arr2);
    int counter = 0;
    int sum = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (arr1[i] >= sum)
        {
            counter++;
            sum = arr1[i]+arr2[i];
        }
        else if(arr1[i]+arr2[i]<sum)
        {
            sum = arr1[i] + arr2[i];
        }
    }
    cout << counter;
    return 0;
}