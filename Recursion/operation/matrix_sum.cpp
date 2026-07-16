#include <bits/stdc++.h>
using namespace std;

int arr[100][100],r,c;

int sum(int i, int j)
{
    if(i == r)
    {
        return 0;
    }

    int x = arr[i][j];

    if(j == c)
      x += sum(i + 1, 0);
       else
         x += sum(i, j + 1);

         return x;
}

int main() 
{
    int i,j;
    cin >> r >> c;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << sum(0, 0);

    return 0;
}