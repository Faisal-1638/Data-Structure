#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
      
        int pos;
        cin >> pos;
    
        for(int i = pos; i < n-1; i++)
        {
            v[i] = v[i+1];
        }

          v.pop_back();
          n--;

          for(int x : v)
          {
            cout << x << " ";
          }

    
          return 0;
    
}