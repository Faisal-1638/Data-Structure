#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr)
{
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    vector<int> arr = {5, 2, 4, 6, 1, 3};

    insertionSort(arr);

    for (int x : arr)
        cout << x << " ";

    return 0;
}

/*
Complexity Analysis
Case	                    Time Complexity
Best Case (already sorted)	    O(n)
Average Case	                O(n²)
Worst Case (reverse sorted)	    O(n²)

Space Complexity: O(1) (in-place)


Properties
 -Stable (equal elements keep their relative order)
 -In-place (uses constant extra memory)
 -Not suitable for very large datasets
 -Excellent for small or nearly sorted arrays

*/