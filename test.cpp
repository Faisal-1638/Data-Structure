#include <bits/stdc++.h>
using namespace std;
void counting(vector<int>& arr)
{
    int n = arr.size();

    int mx = arr[0];
    for(int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
    }

    vector<int> count(mx + 1, 0);
    for(int x : arr)
    {
        count[x]++;
    }

    for(int i = 1; i <= mx; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    vector<int> output(n);

    for(int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for(int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

}

int main()
{
    vector<int> arr = {4,2,2,8,3,3,1};
    counting(arr);

    for(int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}