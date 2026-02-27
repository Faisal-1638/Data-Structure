#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) 
{
    for(int i = 0; i < n; i++) 
    {
        if(arr[i] == target) 
        {
            return i;
        }
    }
    return -1;  
}

int main() 
{
    int arr[] = {4, 2, 7, 1, 9};
    int n = 5;
    int target = 7;

    int result = linearSearch(arr, n, target);

    if(result != -1)
        cout << "Found at index: " << result;
    else
        cout << "Not Found";

    return 0;
}

/*
⏱ Time Complexity
Case	Complexity
Best Case (first element)	O(1)
Worst Case (last/not found)	O(n)
Average Case	O(n)

👉 Why O(n)?
Because in worst case we check all elements.

📦 Space Complexity

O(1)
(Only a few variables used)
*/