#include <bits/stdc++.h>
using namespace std;

int findMax(int arr[], int n)
{
    if(n == 1)
        return arr[0];

    return max(arr[n - 1], findMax(arr, n - 1));
}

int main()
{
    int arr[] = {3, 9, 2, 15, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findMax(arr, n);
}

/*
How recursion returns the answer
Now the function calls return in reverse order.
Phase 2: Coming back
Each waiting call compares two values using max().
Step 1: findMax(arr, 2)

max(arr[1], 3) = max(9, 3)

9


Step 2: findMax(arr, 3)

max(arr[2], 9) = max(2, 9)

9


Step 3: findMax(arr, 4)

max(arr[3], 9) = max(15, 9)

15


Step 4: findMax(arr, 5)

max(arr[4], 15) = max(7, 15)

15



Finally:
cout << 15;


The answer is 15.
*/