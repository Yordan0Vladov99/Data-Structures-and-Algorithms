#include<iostream>

int min(int a, int b)
{
    if (a < b)return a;
    return b;
}

int main()
{
    int N = 0;
    std::cin >> N;
    if (N > 0 && N<=100000)
    {
        int* arr = new int[N];
        for (size_t i = 0; i < N; i++)
        {
            std::cin >> arr[i];
        }
        int max = 0;
        int s = 0;
        for (size_t i = 0; i < N-1; i++)
        {
            for (size_t j = i+1; j < N; j++)
            {
                s = min(arr[i], arr[j])*(j - i);
                if (s > max)
                {
                    max = s;
                }
            }
        }
        std::cout << max;
    }
    return 0;
}