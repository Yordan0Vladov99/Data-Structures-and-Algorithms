#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    int counter = 0;
    cin >> N;
    int* a=new int[N-1];
    int* b=new int[N-1];
    unordered_map<int, int> keys;
    for (int i = 0; i < N-1; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < N-1; i++)
    {
        
        keys[a[i]]++;
        
        if (keys[b[i]] == 0)counter++;
        else
        {
            keys[b[i]]--;
        }
    }
    cout << counter;
    return 0;
}
