#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n, q;
        cin >> n >> q;

        vector<long long> a(n + 1);

        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        while(q--)
        {
            long long l, r, k;
            cin >> l >> r >> k;

            long long sum = 0;
            for(int i = 1; i <= n; i++)
            {
                if(i >= l && i <= r)
                  continue;

                  else 
                    sum += a[i];
            }

            long long newSum = sum + ( r - l + 1) * k;
               
            if(newSum %  2 != 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}