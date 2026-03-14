#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    vector<int> v(n);
     for(int i=0; i < n; i++)
     {
        cin>>v[i];
     }

      int min_idx= 0;
      int mx_idx= 0;

        for(int i=0; i<n; i++)
        {
            if(v[i]<v[min_idx])
             min_idx=i;

              if(v[i]>v[mx_idx])
              mx_idx=i;
        }

        swap(v[min_idx], v[mx_idx]);

           for(int x : v)
           {
            cout<<x<<" ";
           }

           return 0;

    }