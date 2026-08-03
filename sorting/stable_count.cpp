#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr)
{
    int n = arr.size();

    int mx = *max_element(arr.begin(), arr.end());

    vector<int> count(mx + 1, 0);

    // Step 3: Count frequencies
    for (int x : arr)
        count[x]++;

    // Step 4: Convert count[] into prefix sum array
    for (int i = 1; i <= mx; i++)
        count[i] += count[i - 1];

    // Step 5: Create output array
    vector<int> output(n);

    // Step 6: Build output array (RIGHT TO LEFT)
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 7: Copy back
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
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
The stable version of Counting Sort uses:

Find the maximum element.
Count the frequency of each value.
Convert the count array into a prefix sum (cumulative count) array.
Traverse the original array from right to left and place each element into an output array.
Copy the output array back to the original array.

Traversing from right to left ensures that equal elements keep their original relative order, making the algorithm stable.

We'll use this example:

arr = {4, 2, 2, 8, 3, 3, 1}

After counting frequencies and converting to prefix sums, we have:

Index(Value): 0 1 2 3 4 5 6 7 8
Count      : 0 1 3 5 6 6 6 6 7
What does the prefix sum mean?
count[1] = 1  → last 1 goes at index 0
count[2] = 3  → last 2 goes at index 2
count[3] = 5  → last 3 goes at index 4
count[4] = 6  → last 4 goes at index 5
count[8] = 7  → last 8 goes at index 6

So the output array initially is:

Output

_ _ _ _ _ _ _
The Code
for (int i = n - 1; i >= 0; i--)
{
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
}

We'll execute it one iteration at a time.

Iteration 1

i = 6

Element:

arr[6] = 1

Current count:

count[1] = 1

The line

output[count[arr[i]] - 1] = arr[i];

becomes

output[count[1] - 1] = 1;

which becomes

output[1 - 1] = 1;

so

output[0] = 1;

Output

1 _ _ _ _ _ _

Now execute

count[arr[i]]--;

which is

count[1]--;

Now

count[1] = 0
Iteration 2
i = 5

Element

arr[5]=3

Current

count[3]=5

Place

output[5-1]=3;

↓

output[4]=3;

Output

1 _ _ _ 3 _ _

Decrease

count[3]=4
Iteration 3
*/ 