#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

const int p = 127;
const int m = 1e9 + 9;

unsigned long long startHash(string const& s,unsigned k)
{
    unsigned long long h = 0;
    for (int i = 0; i<k;i++) {
        h*= p;
        h+=s[i];
    }
    return h;
}

string rollHash(string s, unsigned k)
{
    unordered_map<long long,int> c;
    unsigned long long h = startHash(s,k);
   
    unsigned long long power = pow(p,k-1);
   
    int mostCommon = 0;
    string common;
    for (int i = k; i < s.size(); i++)
    {
         c[h]++;
         if(c[h] >= mostCommon)
        {
            mostCommon = c[h];
            common = {s,i-k,k};
        }
        
        h -= power * s[i - k];
        h *= p;
        h+= s[i];
       
    }
    c[h]++;
         if(c[h] >= mostCommon)
        {
            mostCommon = c[h];
            common = {s,s.size()-k,k};
        }
    return common;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned n, k;
    cin >> n >> k;
    string a;
    cin.get();
    for(int i =0;i<n;i++)
    {
        a+=cin.get();
    }

    cout << rollHash(a, k);

    return 0;

}
