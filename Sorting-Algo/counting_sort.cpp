#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr)
{
    int mx = *max_element(arr.begin(), arr.end());

    vector<int> count(mx + 1, 0);

    // Count frequency
    for (int x : arr)
        count[x]++;

    // Reconstruct the array
    int index = 0;
    for (int i = 0; i <= mx; i++)
    {
        while (count[i] > 0)
        {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main()
{
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    countingSort(arr);

    for (int x : arr)
        cout << x << " ";

    return 0;
}



/*

Time Complexity
Let:

n = number of elements
k = maximum value in the array

Step	            Complexity
Find maximum	      O(n)
Count frequencies	  O(n)
Build prefix sums	  O(k)
Build output array	  O(n)
Copy back	          O(n)
Total	              O(n + k)

If k ≤ n then:

O(n+k)=O(n)

Space Complexity

Count array: O(k)
Output array: O(n)

Total auxiliary space: O(n + k)

Advantages
  -Very fast when the value range (k) is small.
  -Stable sorting algorithm.
  -Faster than O(n log n) comparison sorts for suitable data.
Disadvantages
  -Works only for integer keys (or data that can be mapped to integers).
  -Not efficient if the range of values (k) is much larger than the number of elements (n), because the count array becomes large.
  -Requires extra memory for the count and output arrays.
  
-Suppose the input is:

[2, 5, 1000000]

Then the count array size must be:

1000000 + 1

Even though there are only 3 elements, it needs over 1 million array positions, wasting memory.

Time Complexity: O(n + k)
Space Complexity: O(k)

where k = range of values.
*/


