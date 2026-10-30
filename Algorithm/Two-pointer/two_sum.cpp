#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 6};
    int target = 7;

    int l = 0;
    int r = v.size() - 1;

    bool found = false;

    int idx1, idx2;

    while(l < r)
    {
        int sum = v[l] + v[r];

        if(sum == target)
        {
            idx1 = l;
            idx2 = r;

            found = true;
            break;
        }
        else if(sum < target)
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    if(found)
    {
        cout << idx1 << " " << idx2 << endl;
    }
    else
    {
        cout << "No pair found" << endl;
    }
}

// for sorted array