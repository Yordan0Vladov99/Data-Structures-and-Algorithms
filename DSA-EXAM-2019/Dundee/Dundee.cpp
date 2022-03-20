#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
#include <set>
#include<string>

using namespace std;


int main() {
    string a;
    string b;
    unordered_map<string, int> M;
    set<string> ans;
    while (cin >> a)
    {
        M[a]++;
    }
    for (auto i : M)
    {
        if (i.second == 1)ans.insert(i.first);
    }
    for (auto i : ans)
    {
        cout << i << endl;
    }


    return 0;
}
