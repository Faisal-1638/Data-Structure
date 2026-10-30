#include <bits/stdc++.h>
using namespace std;

int partitionArray(vector<int>& arr, int low, int high) {

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {

        if (arr[j] < pivot) {
            i++;

            swap(arr[i], arr[j]);
        }
    }

    // Put pivot in its correct position
    swap(arr[i + 1], arr[high]);

    return i + 1;
}


void quickSort(vector<int>& arr, int low, int high) {

    if (low < high) {

        // Divide
        int pivotIndex = partitionArray(arr, low, high);

        // Conquer
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


int main() {

    vector<int> arr = {10, 7, 8, 9, 1, 5};

    int n = arr.size();

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}

/*
//randomized quicksort
 expected O(n log n)

#include <bits/stdc++.h>
using namespace std;

int randomizedPartition(vector<int>& a, int low, int high) {

    int randomIndex = low + rand() % (high - low + 1);

    swap(a[randomIndex], a[high]);

    int pivot = a[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);

    return i + 1;
}

void randomizedQuickSort(vector<int>& a, int low, int high) {

    if (low < high) {

        int p = randomizedPartition(a, low, high);

        randomizedQuickSort(a, low, p - 1);
        randomizedQuickSort(a, p + 1, high);
    }
}


*/
/*
Quick Sort

Quick Sort is also a Divide and Conquer algorithm, like Merge Sort.

The main idea is:

Choose a pivot → Partition the array → Recursively sort the left and right parts

Example

Consider:

[10, 7, 8, 9, 1, 5]

Suppose we choose the last element as pivot:

pivot = 5

After partitioning:

[1] [5] [10, 7, 8, 9]
     ↑
   pivot

Everything smaller than 5 is on the left, and everything larger than 5 is on the right.

Then recursively apply Quick Sort:

[1]    [10, 7, 8, 9]
          ↓
       [7, 8, 9] [10]
          ↓
       [7] [8, 9]
             ↓
          [8] [9]

Final:

[1, 5, 7, 8, 9, 10]

Understand partition()

This is the most important part:

int pivot = arr[high];

For:

[10, 7, 8, 9, 1, 5]
                    ↑
                  pivot

pivot = 5.

We want:

smaller than 5 | 5 | greater than 5

The loop:

for (int j = low; j < high; j++) {

    if (arr[j] < pivot) {
        i++;
        swap(arr[i], arr[j]);
    }
}

moves elements smaller than the pivot to the left.

Finally:

swap(arr[i + 1], arr[high]);

puts the pivot into its correct position.

Quick Sort = Divide and Conquer
             [10, 7, 8, 9, 1, 5]
                       |
                  Choose Pivot
                       |
                      [5]
                       |
                Partition
                 /       \
             smaller    larger
                |          |
             Quick       Quick
             Sort        Sort
                \          /
                 \        /
                  Sorted
Complexity
Case	Time
Best case	Θ(n log n)
Average case	Θ(n log n)
Worst case	Θ(n²)

Worst case can happen when the pivot repeatedly becomes the smallest or largest element, producing very unbalanced partitions.

Space: O(log n) average due to recursion stack, O(n) worst case.

Merge Sort vs Quick Sort
	Merge Sort	Quick Sort
Technique	Divide & Conquer	Divide & Conquer
Average	Θ(n log n)	Θ(n log n)
Worst	Θ(n log n)	Θ(n²)
Extra array	Yes	No
Main operation	Merge	Partition

The key difference to remember:

Merge Sort: Divide first, then merge sorted parts.
Quick Sort: Choose a pivot, partition around it, then sort the parts.
*/