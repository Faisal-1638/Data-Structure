#include<bits/stdc++.h>
using namespace std;
int main()
{
    int M,N;
    cin>>M>>N;
    int A[M][N];
    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            cin>>A[i][j];
        }
    }

    int X;
    cin>>X;
    bool found=false;

    for(int i=0; i<M; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(A[i][j]==X)
            {
                found=true;
                break;
            }
        }
    }

    if(found)
        cout<<"will not take number\n";
    else
        cout<<"will take number\n";


    return 0;
}