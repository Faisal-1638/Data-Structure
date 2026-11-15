//uses Tabulation (Bottom-Up DP).
#include <bits/stdc++.h>
using namespace std;

#define MOD 10000007

int main() {

    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++) {

        vector<long long> dp(10001);

        for (int i = 0; i < 6; i++) {
            cin >> dp[i];
        }

        int n;
        cin >> n;

        for (int i = 6; i <= n; i++) {

            dp[i] = 0;

            for (int j = 1; j <= 6; j++) 
            {
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }

        cout << "Case " << cs << ": " << dp[n] << endl;
    }

    return 0;
}