#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    //int a[n], prefix[n];
    vector<int> a(n), prefix(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    prefix[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    // Output prefix array
    for (int i = 0; i < n; i++) {
        cout << prefix[i] << " ";
    }

    return 0;
}


