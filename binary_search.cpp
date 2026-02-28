#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int key)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;   // safer formula

        if (arr[mid] == key)
            return mid;          // return index

        else if (key < arr[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;   // if not found
}

int main()
{
    vector<int> arr = {10, 25, 30, 45, 60};
    int key = 45;

    int result = binarySearch(arr, key);

    if (result != -1)
        cout << "Element found at index: " << result;
    else
        cout << "Element not found";

    return 0;
}