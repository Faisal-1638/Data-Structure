//Find the minimum number of coins required.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, amount;
    cin >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cin >> amount;

    vector<int> dp(amount + 1, 1e9);

    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {

        for (int coin : coins) {

            if (coin <= i) 
            {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }

    if (dp[amount] == 1e9)
        cout << -1 << endl;
    else
        cout << dp[amount] << endl;

    return 0;
}

/*
 Complexity
Let:
- A = target amount
- N = number of coin denominations
Complexity	Value
Time	O(A * N)
Space	O(A)
*/

/*
Another Coin Change Version: Count the Number of Ways
Sometimes the question asks:

"How many different combinations can make the target amount?"

For example:

Coins = {1, 2, 3}

Amount = 4

Possible combinations:
1. 1 + 1 + 1 + 1
2. 1 + 1 + 2
3. 2 + 2
4. 1 + 3
Answer = 4.
C++ Code
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, amount;
    cin >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cin >> amount;

    vector<long long> dp(amount + 1, 0);

    dp[0] = 1;

    for (int coin : coins) {

        for (int i = coin; i <= amount; i++) {

            dp[i] += dp[i - coin];
        }
    }

    cout << dp[amount] << endl;

    return 0;
}
*/