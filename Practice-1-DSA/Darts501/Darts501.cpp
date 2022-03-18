#include<iostream>
using namespace std;
int main()
{
    const int S = 21;
    int SingleArr[S];
    int DoubleArr[S];
    int TripleArr[S];
    int N = 0;
    cin >> N;
    int counter = 0;
    int res1 = 0;
    int res2 = 0;
    int res3 = 0;
    int res4 = 0;
    int res5 = 0;
    int res6 = 0;
    int res7 = 0;
    int res8 = 0;
    int res9 = 0;
    for (size_t i = 0; i < S; i++)
    {
        SingleArr[i] = i+1;
        DoubleArr[i] = 2 * (i+1);
    }
    for (size_t i = 0; i < S; i++)
    {
        TripleArr[i] = 3 * i;
    }
    SingleArr[S-1] = 25;
    DoubleArr[S-1] = 50;
    for (size_t i = 0; i < S; i++)
    {
        for (size_t j = 0; j < S; j++)
        {
            res1 = SingleArr[i] + SingleArr[j];
            res2 = DoubleArr[i] + DoubleArr[j];
            res3 = TripleArr[i] + TripleArr[j];
            res4 = SingleArr[i] + DoubleArr[j];
            res5 = DoubleArr[i] + TripleArr[j];
            res6 = SingleArr[i] + TripleArr[j];
            res7 = TripleArr[i] + SingleArr[j];
            res8 = TripleArr[i] + DoubleArr[j];
            res9 = DoubleArr[i] + SingleArr[j];
            for (size_t k = 0; k < S; k++)
            {
                if (res1 + DoubleArr[k] == N)counter++;
                if (res2 + DoubleArr[k] == N)counter++;
                if (res3 + DoubleArr[k] == N)counter++;
                if (res4 + DoubleArr[k] == N)counter++;
                if (res5 + DoubleArr[k] == N)counter++;
                if (res6 + DoubleArr[k] == N)counter++;
                if (res7 + DoubleArr[k] == N)counter++;
                if (res8 + DoubleArr[k] == N)counter++;
                if (res9 + DoubleArr[k] == N)counter++;
            }
        }
    }
    for (size_t i = 0; i < S; i++)
    {
        if (DoubleArr[i] == N)counter++;
    }
    for (size_t i = 0; i < S; i++)
    {
        for (int j = 0;j < S; j++)
        {
            if (SingleArr[i] + DoubleArr[j] == N)counter++;
            if (DoubleArr[i] + DoubleArr[j] == N)counter++;
            if (TripleArr[i] + DoubleArr[j] == N)counter++;
        }
    }
    cout << counter;

    return 0;
}