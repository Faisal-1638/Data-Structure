#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& a, int target) {
    int low = 0;
    int high = a.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == target)
            return mid;

        else if (a[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> a = {2, 5, 8, 12, 16, 23, 38, 56};

    int target;
    cin >> target;

    int index = binarySearch(a, target);

    if (index != -1)
        cout << "Found at index " << index << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}

/*
⏱ Time Complexity:
   O(log n) ->worst/average case
   Best Case: O(1)
   suitable for sorted data, Binary search works by checking the middle item and deciding whether to search the left half or the right half.

For unsorted data, Binary Search cannot be used directly because it requires the data to be sorted.

Options for Unsorted Data
(1) Linear Search (Best choice)
    No sorting required.
    Time Complexity: O(n).

(2) Sort first, then Binary Search
   Sorting: O(n log n)
   Binary Search: O(log n)
   Total: O(n log n).
Useful only if you need to perform many searches on the same data.

(3) Hashing (Hash Table)
Average search: O(1).
Best choice if frequent searches are needed and order is not important.

For unsorted data, Binary Search is not suitable because it requires a sorted array. 
The best search method is Linear Search, which works directly on unsorted data with O(n) time complexity. 
If many searches are required, the data can first be sorted or stored in a hash table for faster searches.
*/