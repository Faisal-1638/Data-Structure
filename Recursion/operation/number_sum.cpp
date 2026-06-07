#include <bits/stdc++.h>
using namespace std;

int sum(int x)
{
    if(x == 0)
     return x;

     int sub = x / 10;
     int pos = sum(sub);
     int rem = x % 10;
     int s = pos + rem;
     return s;
}


int main()
{
    int x;
    cin >> x;
    cout << sum(x);
}