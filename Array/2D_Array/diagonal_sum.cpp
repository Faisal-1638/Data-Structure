#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int> (n)); //square matrix

    for(int i = 0;i < n; i++)
    {
       for(int j = 0;  j < n; j++)
       {
           cin >> arr[i][j];
       }
    }


        int majorsum = 0;
        int minorsum = 0;
        for(int i = 0;i < n; i++)
        {
            for(int j = 0;  j < n; j++)
            {
                if(i == j)
                {
                    majorsum += arr[i][j];
                }

                    if(i + j == n - 1)
                    {
                        minorsum += arr[i][j];
                    }
                
            }
        }


        cout<< "Major Diagonal Sum: " << majorsum << "\n";
        cout<< "Minor  Diagonal Sum: " << minorsum << "\n";



    return 0;
     
}