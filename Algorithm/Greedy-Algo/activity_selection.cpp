
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    // Sort activities by finishing time
    sort(a.begin(), a.end(),
         [](auto x, auto y) // This is a lambda function in C++. It is used here to tell sort() how to sort activities by their finishing time.
         {
             return x.second < y.second;
         });

    int cnt = 0;
    int lastEnd = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (a[i].first >= lastEnd)
        {
            cnt++;
            lastEnd = a[i].second;
        }
    }

    cout << cnt << '\n';

    return 0;
}

/*
Example input
6
1 3
2 5
3 4
5 7
6 9
8 10


Output
4


How it works
1. Each activity has a start time and an end time.
2. Sort activities by their end times.
3. Select an activity if its start time is greater than or equal to the previous selected activity's end time.
4. Count the selected activities.
Time complexity: O(n log n), because of sorting.

Greedy idea: Always choose the compatible activity that finishes earliest, leaving as much time as possible for the remaining activities.
*/