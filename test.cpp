#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    vector<int> v(n);

    
   int sum = 0;
   for(int i = 0; i < n; i++)
   {
    cin >> v[i];
    sum += v[i];
   }

   if(sum == n)
   {
     if(n == 2)
      cout << -2 << "\n";

      else 
       cout << n - 4 << "\n";
   }

   else
   {
        for(int i = 0; i < n -1 ; i++)
        {
            if(v[i] == -1 && v[i + 1] == -1)
            {
                v[i] = 1;
                v[i + 1] = 1;
                break;
            }
        }
            int sum = 0;
            for(int i = 0; i < n ; i++)
            {
                sum += v[i];
            } 
        
        cout << sum << "\n";
    }

  }
}