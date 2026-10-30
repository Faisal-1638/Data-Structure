#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Bubble Sort
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swapping happened, array is already sorted
        if (!swapped)
            break;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
    Time Complexity

Let the number of elements be n.

1. Worst Case — O(n²)

Consider a reverse-sorted array:

[5, 4, 3, 2, 1]

Almost every pair needs to be swapped.

Number of comparisons is approximately:

(n-1) + (n-2) + ... + 1

This is:

n(n−1) / 2
	​


Therefore:

O(n^2)
	​

2. Average Case — O(n²)

For randomly ordered data, Bubble Sort generally performs many comparisons and swaps.

O(n
2
)
	​

3. Best Case — O(n)

With the swapped optimization, if the array is already sorted:

[1, 2, 3, 4, 5]

Bubble Sort makes one pass, sees that no swaps occurred, and stops.

Therefore:

O(n)
	​


Important: Without the swapped optimization, even an already-sorted array takes O(n²).

Space Complexity

Bubble Sort sorts the array in place.

It only needs a few extra variables:

swapped
i
j

Therefore:

O(1)
	​


So Bubble Sort has constant auxiliary space.

Bubble Sort is rarely used for serious large-scale sorting because it is slow.

It is mainly useful for:

1. Learning sorting algorithms

It is one of the easiest algorithms for understanding:

comparison
swapping
loops
sorting
time complexity
2. Very small datasets

If you only have a few elements, its simplicity can be acceptable.

3. Educational/interview purposes

It is commonly used to test whether you understand:

nested loops
Big-O analysis
best/average/worst cases
in-place algorithms
4. Detecting an already-sorted array

The optimized version can determine that an array is sorted after one pass.

Bubble Sort vs Other Sorting Algorithms
Algorithm	Best	Average	Worst	Space	Stable?
Bubble Sort	O(n)	O(n²)	O(n²)	O(1)	✅
Selection Sort	O(n²)	O(n²)	O(n²)	O(1)	❌
Insertion Sort	O(n)	O(n²)	O(n²)	O(1)	✅
Merge Sort	O(n log n)	O(n log n)	O(n log n)	O(n)	✅
Quick Sort	O(n log n)	O(n log n)	O(n²)	O(log n)**	❌
Heap Sort	O(n log n)	O(n log n)	O(n log n)	O(1)	❌

* Standard Selection Sort is not stable.
** Typical recursive implementation; exact auxiliary space depends on implementation/pivot strategy.

Which One Is Better?

For large datasets, Bubble Sort is generally a poor choice.

For example, suppose:

n = 1,000,000

Bubble Sort can require roughly:

2
1,000,000(999,999)
	​


comparisons in the worst case — approximately 500 billion comparisons.

An O(n log n) algorithm is dramatically more efficient.

When to Choose Which?
Bubble Sort

Use when:

Very small data
       ↓
Learning / teaching
       ↓
Simple implementation
Insertion Sort

Very good when:

Small dataset
OR
Data is already/nearly sorted
Merge Sort

Good when:

Guaranteed O(n log n)
+
Stable sorting
Quick Sort

Often very fast in practice:

Average O(n log n)
+
Good cache performance
+
Usually in-place

But poor pivot choices can produce O(n²).

Heap Sort

Useful when you want:

O(n log n) worst-case
+
O(1) extra space
The Most Important Comparison

If you're studying Big-O, remember this:

                    Best       Average      Worst
-------------------------------------------------------
Bubble Sort         O(n)       O(n²)        O(n²)
Insertion Sort      O(n)       O(n²)        O(n²)
Selection Sort      O(n²)      O(n²)        O(n²)
Merge Sort          O(nlogn)   O(nlogn)      O(nlogn)
Quick Sort          O(nlogn)   O(nlogn)      O(n²)
Heap Sort           O(nlogn)   O(nlogn)      O(nlogn)
Interview answer

If an interviewer asks "What is Bubble Sort and its efficiency?", you can say:

Bubble Sort is a comparison-based sorting algorithm that repeatedly compares adjacent elements and swaps them when they are in the wrong order. Its worst-case and average-case time complexity is O(n²), while the optimized version has O(n) best-case complexity when the array is already sorted. It uses O(1) extra space and is stable. It is mainly useful for learning, small datasets, and educational purposes, but it is generally inefficient for large datasets compared with O(n log n) algorithms such as Merge Sort, Heap Sort, and typical Quick Sort.
*/