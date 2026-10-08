#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int current = a[0];
    int maximum = a[0];

    for(int i = 1; i < n; i++)
    {
        current = max(a[i], current + a[i]);
        maximum = max(maximum, current);
    }

    cout << maximum << endl;
}