#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    // DP table
    vector<int> dp(n + 1);

    // Base cases
    dp[0] = 0;
    dp[1] = 1;

    // Fill the table from bottom to top
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;

    return 0;
}

/*
Time Complexity:
O(n)
Space Complexity:
The dp array contains n + 1 elements.
O(n)

*/
/*

//Optimized Space Version
//Since we only need the previous two values, we don't actually need the whole DP table:

#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i <= n; i++) {
        int current = prev1 + prev2;

        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}

int main() {
    int n;

    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;

    return 0;
}

For this optimized version:

TC = O(n)
SC = O(1)

*/