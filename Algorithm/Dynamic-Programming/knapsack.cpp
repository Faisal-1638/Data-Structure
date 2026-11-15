#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    vector<long long> dp(W + 1, 0);

    for (int i = 0; i < n; i++) 
    {
        int weight;
        long long value;

        cin >> weight >> value;

        for (int w = W; w >= weight; w--) 
        {
            dp[w] = max( dp[w],value + dp[w - weight]);
        }
    }

    cout << dp[W] << endl;

    return 0;
}
