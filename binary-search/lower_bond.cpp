#include<bits/stdc++.h>
using namespace std;
int lowerBound(vector<int>& a, int x)
{
    int low = 0;
    int high = a.size() - 1;
    int ans = a.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {2,4,4,4,6,8,10};
    cout << lowerBound(arr, 5);
}


/*
#include <iostream>
#include <vector>
using namespace std;

int upperBound(vector<int>& arr, int x)
{
    int n = arr.size();

    int l = -1;
    int r = n;

    while (l + 1 < r)
    {
        int mid = (l + r) / 2;

        if (arr[mid] >= x)
            r = mid;
        else
            l = mid;
    }

    return r;
}

int main()
{
    vector<int> arr = {2, 4, 4, 4, 6, 8, 10};

    int x;
    cout << "Enter x: ";
    cin >> x;

    int index = lowerBound(arr, x);

    if (index == arr.size())
        cout << "lower Bound does not exist.\n";
    else
    {
        cout << "lower Bound Index = " << index << endl;
        cout << "lower Bound Value = " << arr[index] << endl;
    }

    return 0;
}

*/
/*
STL

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> a = {2, 4, 4, 4, 7, 9, 10};

    int x = 4;

    int lb = lower_bound(a.begin(), a.end(), x) - a.begin();
    int ub = upper_bound(a.begin(), a.end(), x) - a.begin();

    cout << "Lower Bound Index = " << lb << endl;
    cout << "Upper Bound Index = " << ub << endl;

    return 0;
}
*/