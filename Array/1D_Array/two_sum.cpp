// //Brute Force Solution

// Check every pair.

// Time Complexity
// O(n²)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int target = 6;

    for(int i = 0; i < v.size(); i++)
    {
        for(int j = i + 1; j < v.size(); j++)
        {
            if(v[i] + v[j] == target)
            {
                cout << i << " " << j << endl;
            }
        }
    }
}

/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    int target = 6;

    bool found = false;

    int idx1, idx2;

    for(int i = 0; i < v.size(); i++)
    {
        for(int j = i + 1; j < v.size(); j++)
        {
            if(v[i] + v[j] == target)
            {
                idx1 = i;
                idx2 = j;

                found = true;
                break;
            }
        }

        if(found)
            break;
    }

    if(found)
    {
        cout << idx1 << " " << idx2 << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++)
    {
        int need = target - arr[i];

        if(mp.find(need) != mp.end())
        {
            cout << mp[need] << " " << i << endl;
            return 0;
        }

        mp[arr[i]] = i;
    }

    cout << "No solution" << endl;

    return 0;
}

. Time and Space Complexity
Complexity	Value	Reason
Time	O(n) average One traversal, O(1) average hash operations
Space	O(n) Hash map can store n elements
*/