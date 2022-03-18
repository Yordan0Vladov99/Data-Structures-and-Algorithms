#include <iostream>
#include <stack>

long long counter = 0;
int k = 0;

void solve(int* arr, int size)
{
    std::deque<int> nums;
    std::deque<int> min;
    std::deque<int> max;

    nums.push_back(arr[0]);
    min.push_back(arr[0]);
    max.push_back(arr[0]);
    //counter++;
    int i = 1;
    while (i <= size)
    {
        while (max.front() - min.front() <= k)
        {
            counter += nums.size();
            nums.push_back(arr[i]);
            if (arr[i] < min.front())
            {
                min.clear();
                min.push_back(arr[i]);
            }
            else
            {
                while (min.back() > arr[i])
                {
                    min.pop_back();
                }
                min.push_back(arr[i]);
            }
            if (arr[i] > max.front())
            {
                max.clear();
                max.push_back(arr[i]);
            }
            else
            {
                while (max.back() < arr[i])
                {
                    max.pop_back();
                }
                max.push_back(arr[i]);
            }
            i++;
            if(i > size)
            {
                break;
            }
            
        }
        while (max.front() - min.front() > k)
        {
            int c = nums.front();
            if (c == min.front())
            {
                min.pop_front();
            }
            if (c == max.front())
            {
                max.pop_front();
            }
            nums.pop_front();
        }
    }
    
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n >> k;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    solve(arr, n);
    std::cout << counter;
    return 0;
}