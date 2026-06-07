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
*/