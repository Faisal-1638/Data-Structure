#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return left;
}

int main() {
    vector<int> nums = {1, 3, 5, 6,9};

    cout << searchInsert(nums, 5) << "\n"; // 2
    cout << searchInsert(nums, 2) << "\n"; // 1
    cout << searchInsert(nums, 7) << "\n"; // 4
    cout << searchInsert(nums, 0) << "\n"; // 0
    cout << searchInsert(nums, 8) << "\n"; // 0

    return 0;
}

/*
Walkthrough
Example 1: nums = [1,3,5,6], target = 5
left=0, right=3 → mid=1 → nums[1]=3 < 5 → left=2
left=2, right=3 → mid=2 → nums[2]=5 == 5 → return 2 ✓
Example 2: nums = [1,3,5,6], target = 2
left=0, right=3 → mid=1 → nums[1]=3 > 2 → right=0
left=0, right=0 → mid=0 → nums[0]=1 < 2 → left=1
left=1 > right=0 → exit → return left=1 ✓
Example 3: nums = [1,3,5,6], target = 7
left=0, right=3 → mid=1 → nums[1]=3 < 7 → left=2
left=2, right=3 → mid=2 → nums[2]=5 < 7 → left=3
left=3, right=3 → mid=3 → nums[3]=6 < 7 → left=4
left=4 > right=3 → exit → return left=4 ✓
Why left is Always the Answer on Miss
ScenarioWhat happensTarget is too largeleft keeps moving right until it passes right — sits at insertion pointTarget is too smallright keeps moving left — left stays at the first element ≥ targetTarget between elementsLoop tightens until left lands on the first element > target
The loop invariant guarantees that left always points to the position where the target belongs.
Time: O(log n) — search space halves each iteration
Space: O(1) — no extra memory used
*/