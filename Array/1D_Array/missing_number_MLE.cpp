#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    
    vector<bool> seen(n + 1, false);

    // Mark present numbers
    for (int x : nums) {
        seen[x] = true;
    }

    // Find missing number
    for (int i = 0; i <= n; i++) {
        if (!seen[i]) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {3, 0, 1};

    cout << "Missing number: " << missingNumber(nums) << endl;

    return 0;
}

/*
> **Time Complexity:** `O(N)`
**Space Complexity:** `O(N)` (extra array grows with input size)
> 

**Problem with this approach:** If `N = 10⁹`, allocating additional `N+1` boolean values is impossible → **Memory Limit Exceeded (MLE)**.
*/

/*
XOR Approach...->

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    int n = nums.size();

    int xorAll = 0;   // XOR of numbers from 0 to n
    int xorArr = 0;   // XOR of array elements

    // XOR all indices (0 to n-1) and array elements
    for (int i = 0; i < n; i++) {
        xorAll ^= i;
        xorArr ^= nums[i];
    }

    // XOR last number n
    xorAll ^= n;

    // missing number = xorAll ^ xorArr
    return xorAll ^ xorArr;
}

int main() {
    vector<int> nums = {3, 0, 1};

    cout << "Missing number: " << missingNumber(nums) << endl;

    return 0;
}
*/