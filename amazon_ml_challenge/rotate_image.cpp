#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[][3] =
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};

    int m = 3; // rows
    int n = 3; // columns

    for (int i = 0; i < m / 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            swap(arr[i][j], arr[n - i - 1][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    cout << "Matrix after performing 90 degrees rotation: " << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}