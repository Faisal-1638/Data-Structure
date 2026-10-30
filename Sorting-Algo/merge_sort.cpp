#include <bits/stdc++.h>
using namespace std;

// Merge two sorted parts
void merge(vector<int>& arr, int left, int mid, int right) {

    vector<int> temp;

    int i = left;      // first part
    int j = mid + 1;   // second part

    // Compare elements from both parts
    while (i <= mid && j <= right) {

        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Remaining elements of left part
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Remaining elements of right part
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy sorted elements back to original array
    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}


// Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {

    // Base case
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    // Divide
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Combine
    merge(arr, left, mid, right);
}


int main() {

    vector<int> arr = {38, 12, 27, 43, 9, 31, 18, 25};

    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}

/*
The time complexity is Θ(n log n).

Divide: O(log n) levels
Merge at each level: O(n)
Therefore: O(n log n)

Why is Merge Sort O(n log n)?

Answer:

log n levels × O(n) work per level
= O(n log n)

How mergeSort() works

Suppose:

[38, 12, 27, 43]

First:

int mid = left + (right - left) / 2;

Divides it:

[38, 12]    [27, 43]

Then recursively divides again:

[38] [12]    [27] [43]

Now the recursion reaches the base case:

if (left >= right)
    return;

because a single element is already sorted.

Then merge() starts

We have:

[38] [12]

Compare:

38 vs 12

12 is smaller:

[12, 38]

Similarly:

[27] [43]
      ↓
[27, 43]

Then:

[12, 38] + [27, 43]

Compare one by one:

12 vs 27 → 12
38 vs 27 → 27
38 vs 43 → 38
remaining → 43

Result:

[12, 27, 38, 43]
The most important part

This:

mergeSort(arr, left, mid);
mergeSort(arr, mid + 1, right);
merge(arr, left, mid, right);

represents Divide and Conquer:

             Merge Sort
                 |
              DIVIDE
             /      \
          left      right
           /          \
        divide       divide
         ↓             ↓
       single        single
       elements      elements
           \          /
            CONQUER
               |
             MERGE
               |
          sorted array
Complexity

For n elements:

Divide → log n levels
Merge  → O(n) at each level

Total = O(n log n)

So:

Time Complexity = Θ(n log n)
Space Complexity = O(n) because of the temporary array.
*/