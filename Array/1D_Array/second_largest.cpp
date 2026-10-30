#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        if(v[i] > largest)
        {
            secondLargest = largest;
            largest = v[i];
        }
        else if(v[i] > secondLargest && v[i] < largest)
        {
            secondLargest = v[i];
        }
    }

    if(secondLargest == INT_MIN)
        cout << "No second largest element";
    else
        cout << secondLargest << endl;

    return 0;
}