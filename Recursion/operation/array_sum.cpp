#include <bits/stdc++.h>
using namespace std;

int arraySum(int arr[], int n)
{
    // Base case
    if(n == 0)
        return 0;

    // Recursive case
    return arr[n - 1] + arraySum(arr, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    int n = 5;

    cout << "Sum = " << arraySum(arr, n);

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int i, int n)
{
    if(i == n)
        return 0;

    return arr[i] + sum(arr, i + 1, n);
}

int main()
{
    int arr[] = {1,2,3,4,5};

    int n = 5;

    cout << sum(arr, 0, n);
}
*/