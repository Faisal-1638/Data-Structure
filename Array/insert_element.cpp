#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> v(n);//or use v(n+1) and instead of pushback.

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
      
      int pos, value;
      cin >> pos >> value;

      v.push_back(0);

        for(int i = v.size() - 1; i > pos; i--)
        {
            v[i] = v[i-1];
        }

          v[pos] = value;

          for(int x : v)
          {
            cout << x << " ";
          }

    
          return 0;
    
}

/*
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    // take input
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int pos, value;
    cin >> pos >> value;  // position & value

    // insert at position
    v.insert(v.begin() + pos, value);

    // print vector
    for(int x : v)
    {
        cout << x << " ";
    }

    return 0;
}

*/