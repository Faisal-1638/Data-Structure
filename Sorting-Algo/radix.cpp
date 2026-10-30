#include <bits/stdc++.h>
using namespace std;

// Stable Counting Sort according to digit represented by exp
void countingSort(vector<int>& arr, int exp)
{
    int n = arr.size();
    vector<int> count(10, 0);

    // Count occurrences of current digit
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Prefix sum
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output array (RIGHT TO LEFT)
     vector<int> output(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(vector<int>& arr)
{
    int mx = *max_element(arr.begin(), arr.end());

    // Process each digit
    for (int exp = 1; mx / exp > 0; exp *= 10)
        countingSort(arr, exp);
}

int main()
{
    vector<int> arr = {170,45,75,90,802,24,2,66};

    radixSort(arr);

    for (int x : arr)
        cout << x << " ";

    return 0;
}

/*
Complexity

Let:
n = number of elements
d = number of digits in the largest number
b = base (10 for decimal numbers)
TC -> O(d × (n + b))

Space Complexity

Output array: O(n)
Count array (size 10): O(1)

Overall auxiliary space:  O(n)

One of the main advantages of Radix Sort is that it overcomes the large range limitation of Counting Sort.

Radix Sort overcomes the range problem of Counting Sort because it sorts numbers digit by digit instead of allocating a count array for the entire value range. 
It uses a fixed-size count array (equal to the base, e.g., 10 for decimal), making it efficient even when the input values have a very large range
Radix Sort does not create an array based on the maximum value.

Instead, it sorts one digit at a time using Counting Sort as a stable subroutine.

Example:

329
457
657
839
436
720
355

It sorts by:

Units digit
Tens digit
Hundreds digit

Each pass uses a count array of only 10 elements (0–9) for decimal numbers.

So regardless of whether the largest number is 999 or 999999999, the count array size remains 10.

*/