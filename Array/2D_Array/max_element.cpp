#include<bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin >> row >> col;

    vector<vector<int>> arr(row, vector<int> (col));

    int mx = INT_MIN;
    int r = -1;
    int c = -1;
    for(int i = 0;i < row; i++)
    {
       for(int j = 0;  j < col; j++)
       {
           cin >> arr[i][j];
           mx = max(mx, arr[i][j]);
           r = i;
           c = j;
       }
    }

    cout << mx << "\n";
    cout << "Position = [" << r << ", " << c << "]";

    return 0;
     
}