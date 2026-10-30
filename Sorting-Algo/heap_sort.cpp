#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);// recursive call
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)// i = last non-leaf node denoted by n /2 - 1
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);   // Move max to end
        heapify(arr, i, 0);     // Heapify reduced heap/ recursive call
    }
}

int main() {
    vector<int> arr = {4, 10, 3, 5, 1};

    heapSort(arr);

    for (int x : arr)
        cout << x << " ";

    return 0;
}

/*
**Complexity Analysis**
Operation	       Time Complexity
Build Max Heap	       O(n)
Each Heapify	     O(log n)

Number of Extractions	n − 1

Total Heap Sort	     O(n log n)

**Space Complexity**
Auxiliary Space: O(1) (in-place)
Recursive implementation: O(log n) due to the recursion stack. 
An iterative heapify implementation reduces this to O(1) auxiliary space.

Advantages
    Guaranteed O(n log n) worst-case time.
    n-place sorting (no extra array needed).
    Suitable when worst-case performance matters.

Disadvantages
    Not stable (equal elements may change relative order).
    Usually slower than Quick Sort in practice because of poorer cache locality and more data movement.
*/