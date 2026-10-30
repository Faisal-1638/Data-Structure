#include <bits/stdc++.h>
using namespace std;

int sum(int x)
{

if(x == 0)
 return 0;

 int rem = x / 10;
 int ans = sum(rem);
 int mod = x % 10;
 int pos = ans + mod;
 return pos;

}

int main()
{
    int x = 555;
    cout << sum(x);
}
