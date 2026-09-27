#include<bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin >> n;

   vector<int> a(n);

   for(int i = 0; i < n; i++)
   {
       cin >> a[i];
   }

   int x;
   cin >> x;

   int index = -1;

   for(int i = 0; i < n; i++)
   {
       if(a[i] == x)
       {
           index = i;
           break;
       }
   }

   cout << index;
}

/*
⏱ Time Complexity
Case	                     Complexity
Best Case (first element)	 O(1) ->Reason: The target element is at the first position.
Worst Case (last/not found)	 O(n)
Average Case	             O(n)

👉 Why O(n)?
Because in worst case we check all elements.

📦 Space Complexity

O(1)
(Only a few variables used)
*/