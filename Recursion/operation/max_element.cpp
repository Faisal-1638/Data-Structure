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