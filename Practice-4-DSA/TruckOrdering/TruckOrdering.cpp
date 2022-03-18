#include <iostream>
#include<stack>
#include <algorithm>
using namespace std;
const int start_size = 100000;
bool solve(int* arr,int n)
{
    int small = 1;
    bool place = false;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
         if(arr[i] == small)
        {
           // place = *std::min_element(arr + i+1, arr + n) > * std::min_element(s.arr, s.arr + s.top + 1);
            
            small++;
             continue;
         }
            if (s.empty())
            {
                s.push(arr[i]);
            }
            else if (s.top() < arr[i]&& s.top()==small)
            {
                s.pop();
                small++;
            }
            else if (s.top() < arr[i] && s.top()!=small)
            {
                return false;
            }
            else if (s.top() > arr[i])
            {
                s.push(arr[i]);
            }
        
       
    }
    return 1;
   
}

int main()
{
    int t;
    std::cin >> t;
    int n;
    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            std::cin >> arr[i];
            
        }
        if(n == 0)
        {
            std::cout << "yes\n";
        }
        else
        {
            solve(arr, n) ? std::cout << "yes\n" : std::cout << "no\n";
        }
        
    }
}