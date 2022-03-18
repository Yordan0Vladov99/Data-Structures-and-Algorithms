#include<iostream>
using namespace std;

int main()
{
    int cols = 2;
    int T = 0;
    cin >> T;
    int O = 1;
    int C = 0;
    if (T >= 1 && T <= 10)
    {
        int** arr = new int*[T];
        for (size_t i = 0; i < T; i++)
        {
            arr[i] = new int[cols];

        }

        bool* resultarr = new bool[T];
        for (size_t i = 0; i < T; i++)
        {
            for (size_t j = 0; j < 2; j++)
            {
                cin >> arr[i][j];
            }
        }
        for (size_t i = 0; i < T; i++)
        {
            
            while (O<arr[i][1])
            {
                O++;
                C++;
            }
            while (C<arr[i][0]&& C > 0)
            {
                C += 2;
            }
            if (O==arr[i][1]&&C==arr[i][0])
            {
                resultarr[i] = 1;
            }
            else
            {
                resultarr[i] = 0;
            }
            O = 1;
            C = 0;
        }
        for (size_t i = 0; i < T; i++)
        {
            if (resultarr[i])
            {
                cout << "yes" << endl;
            }
            else cout << "no" << endl;
        }
    }
    return 0;
}