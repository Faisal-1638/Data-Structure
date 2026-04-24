#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int item)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == item)
         return i;
    }

    return -1;
}

int main()
{
    int arr[] = {1, 2, 3 , 4 ,5};
    int n = 5;
    int item = 9;

    int result = search(arr,n, item );

    cout << result <<endl;
    
    
}