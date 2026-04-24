#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int key)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;   

        if (arr[mid] == key)
            return mid;         

        else if (key < arr[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;  
}

int main()
{
    int n; 
    cin >> n;
    vector<int> arr(n);
     for(int i = 0; i < n; i++)
     {
        cin >> arr[i];
     }

      sort(arr.begin(), arr.end());
        
        int key;
        cin >> key;

        int result = binarySearch(arr, key);

        if (result != -1)
          cout << "Element found at index: " << result;
            else
                cout << "Element not found";

    return 0;
}

/*
Why Binary Search?
-> It repeatedly divides the search space in half
-> Time complexity: O(log n) (very fast for large data)
✅ Time Complexity = O(log n) ->worst/average case
   Best Case: O(1) // when middle element is the expected element
-> Much better than Linear Search (O(n))

🔍 Binary Search Algorithm

Idea

Compare the target with the middle element:

If equal → found
If smaller → search left half
If larger → search right half


✅ Time Complexity = O(log n) ->worst/average case
   Best Case: O(1)

👉 Reason: The target element is found at the middle in the first comparison.

❓ Why not O(n)?

Because binary search does NOT check every element.

Instead, every step:

It cuts the search space into half.

🔎 Step-by-Step Shrinking

Suppose array size = n

After each iteration:

Step 1 → n
Step 2 → n/2
Step 3 → n/4
Step 4 → n/8
Step 5 → n/16
...

We keep dividing by 2 until it becomes 1.

So we solve:

n / (2^k) = 1

Multiply both sides by 2^k:

n = 2^k

Take log base 2:

k = log₂(n)

That means maximum steps = log₂(n)

👉 Therefore time complexity = O(log n)

📊 Example

If:

n = 8 → max 3 steps

n = 16 → max 4 steps

n = 32 → max 5 steps

n = 1,000,000 → about 20 steps only 😲

That’s why binary search is VERY fast.

📌 Best, Average, Worst Case
Case	Time Complexity
Best case	O(1) (found at first mid)
Average case	O(log n)
Worst case	O(log n)

Worst case happens when:

Element is not present

Or found at last possible step

🚀 Why Interviewers Love It?

Because:

Much faster than Linear Search → O(n)

Used in many advanced algorithms

Base of divide-and-conquer concept
*/