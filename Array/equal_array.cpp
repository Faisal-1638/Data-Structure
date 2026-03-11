#include<bits/stdc++.h>
using namespace std;
int main()
{
     int n,k;
     cin >> n >> k;

     vector<int> v(n);

        for(int i = 0; i < n; i++)
        {
          cin >> v[i];
        }

         int mx = *max_element(v.begin(), v.end());
         int opr=0;
          
          for(int x : v)
          {
            if((mx - x) % k != 0)
            {
                cout << -1;
                return 0;
            }
             
              opr += (mx - x) / k; 
          }

          cout << opr;

          return 0;

}


