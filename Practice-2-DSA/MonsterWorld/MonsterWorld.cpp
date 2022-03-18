#include<iostream>
#include<cmath>
using namespace std;
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (size_t j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int c = arr[i];
            arr[i] = arr[j];
            arr[j] = c;
        }
    }
    int c = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = c;
    return (i + 1);
}
int partition_r(int arr[], int low, int high)
{
    int pi = rand() % (high - low) + low;
    int c = arr[pi];
    arr[pi] = arr[high];
    arr[high] = c;
    return partition(arr, low, high);
}
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition_r(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n = 0;
    int x = 0;
    int counter = 0;
    cin >> n;
    cin >> x;
    if (x <= 2 * pow(10, 5) && n <= 2 * pow(10, 5))
    {
        int* arr = new int[n];
        for (size_t i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        QuickSort(arr, 0, n - 1);
        int blastradius = 0;
        int value = 0;
        
        for (int i = n-1; i >= 0; i--)
        {
            if (arr[i] == value)
            {
                arr[i] = 0;
            }
            else
            {
                value = arr[i];
                arr[i] -= blastradius;
                if (arr[i] > 0)
                {
                    arr[i] = 0;
                    blastradius += x;
                    counter++;
                }
            }
        
        }
        cout << counter;
    }
    return 0;
}