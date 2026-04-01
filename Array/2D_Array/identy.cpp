#include <bits/stdc++.h>
using namespace std;

int main()
{
    int row, col;
    cin >> row >> col;

    vector<vector<int>> A(row, vector<int>(col));

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> A[i][j];

        bool identy = true;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
               if((i == j && A[i][j] != 1) || (i != j && A[i][j] != 0))
               {
                identy = false;
                break; 
               }
                
            }
        }

            if(identy)
             cout << "Yes";
             else 
              cout << "No";

    return 0;
}