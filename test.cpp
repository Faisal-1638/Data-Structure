#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        bool f = true;
        for(int i = 2; i < n; i++)
        {
            if((n + 1) % i == 0)
            {
             f = false;
             break;
            }
        }

        if(f)
        cout <<  "YES\n";

        else
         cout << "NO\n";
        

    }

    return 0;
}