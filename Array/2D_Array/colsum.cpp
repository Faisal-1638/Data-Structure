#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin >> row >> col;

    vector<vector<int>> arr(row, vector<int> (col));

    for(int i = 0;i < row; i++)
       for(int j = 0;  j < col; j++)
           cin >> arr[i][j];

    for(int i = 0; i < col; i++)
    {
      int sum = 0;
      
       for(int j = 0; j < row; j++)
       {
        sum += arr[j][i];
       }

       cout << sum << "\n";
    }

    return 0;
     
}