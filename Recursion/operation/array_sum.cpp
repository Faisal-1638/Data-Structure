#include <bits/stdc++.h>
using namespace std;

int arr[100],n;
int arrSum(int i)
{
    // Base case
    if(i == n -1)
        return arr[i];

    // Recursive case
    int s = arrSum(i + 1) + arr[i];
    return s;
}

int main()
{
    n = 5;
    for(int i = 0; i < n; i++)
     cin >> arr[i];

    cout << "Sum = " << arrSum(0);

    return 0;
}

/*
without Global

int sum(int arr[], int i, int n)
{
    if(i == n)
        return 0;

    return arr[i] + sum(arr, i + 1, n);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "Sum = " << arrSum(arr, 0, n);

    return 0;
}

*/

/*
Example

Input:

1 2 3 4 5

Execution:

arrSum(0)
= 1 + arrSum(1)
= 1 + 2 + arrSum(2)
= 1 + 2 + 3 + arrSum(3)
= 1 + 2 + 3 + 4 + arrSum(4)
= 1 + 2 + 3 + 4 + 5
= 15

Output:

Sum = 15

Another approach

#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int i, int n)
{
    if(i == 0)
        return arr[0];

    return arr[i] + sum(arr, i - 1, n);
}

int main()
{
    int arr[] = {1,2,3,4,5};

    int n = 5;

    cout << sum(arr, n - 1, n);
}
*/