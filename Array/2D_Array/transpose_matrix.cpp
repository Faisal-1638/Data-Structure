#include<bits/stdc++.h>
using namespace std;
int main()
{
    int row,col;
    cin >> row >> col;

    vector<vector<int>> v(row, vector<int> (col));

    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> v[i][j];
        }
    }

        for(int i = 0; i < col; i++)
        {
            for(int j = 0; j < row; j++)
            {
                cout << v[j][i]<<" ";
            }
            cout<<"\n";
        }

        return 0;

}