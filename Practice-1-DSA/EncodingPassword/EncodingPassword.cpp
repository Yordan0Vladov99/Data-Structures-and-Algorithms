#include <iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    string result;
    int counter=0;
    for (size_t i = 0; i < str.length(); i+=counter,counter=0)
    {
        for (size_t j = i; str[j]==str[i]; j++)
        {
            counter++;
        } 
        
        string s = to_string(counter);
        result += s;
        result+=str[i];
    }
    cout << result;

    return 0;
}