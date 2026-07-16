#include <bits/stdc++.h>
using namespace std;

void digit(long long n)
{
    if(n < 10)
    {
        cout << n << " ";
        return;
    }

    digit(n / 10);
    cout << n % 10 << " ";
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        long long N;
        cin >> N;
        if(N == 0)
         cout << 0;

         else 
          digit(N);

          cout << "\n";
    }

    return 0;
}