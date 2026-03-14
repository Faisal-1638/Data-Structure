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

        bool sorted= true;

        for(int i = 0; i < n-1; i++)
        {
            if(v[i]>v[i+1])
            {
                sorted = false;
                break;
            }
        }

          if(sorted)
           cout<<"YES\n";

           else
            cout<<"NO\n";

    return 0;
}