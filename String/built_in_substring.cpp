#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    string base = "";

    // create long enough repeated string
    for (int i = 0; i < 50; i++) {
        base += "Yes";
    }

    while (t--) {
        string s;
        cin >> s;

        if (base.find(s) != string::npos)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}