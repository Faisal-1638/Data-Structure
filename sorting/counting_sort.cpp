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