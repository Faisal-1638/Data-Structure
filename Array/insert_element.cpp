#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n; 
  vector<int> v(n);//or use v(n+1) and instead of pushback.

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
      
      int pos, value;
      cin >> pos >> value;

      v.push_back(0);// increase vector size by 1;

        for(int i = v.size() - 1; i > pos; i--)
        {
            v[i] = v[i-1];//assume n = 5; size increases ... now n = 6; want 10 insert at pos 2...... v[i] == v[i-1] ..... v[5] becomes 5 ... v[4] becomes 4... v[3] becomes 3 ... v[2] becomes empty... we putt item to v[2]
    
        }

          v[pos] = value;

          for(int x : v)
          {
            cout << x << " ";
          }

    
          return 0;
}
/*
1. Insert at First (pos = 0)
All elements shift
⏱️ O(n) ❌ Worst Case
2. Insert at Middle (pos = n/2)
Half elements shift
⏱️ O(n) (still linear) Average case.
3. Insert at Last (pos = n)
Loop doesn’t run
Direct insert
⏱️  ✅ Best Case O(1) 
When inserting at the end (no shifting needed)

Example:

[1 2 3 4 _] → insert 5 → [1 2 3 4 5]
❌ Worst Case: O(n)
When inserting at the beginning or middle
All elements must shift right

Example:

[1 2 3 4] → insert 0 at start
→ shift all → [0 1 2 3 4]

👉 Shifting ≈ n operations → O(n)
*/
/*
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    // take input
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int pos, value;
    cin >> pos >> value;  // position & value

    // insert at position
    v.insert(v.begin() + pos, value);

    // print vector
    for(int x : v)
    {
        cout << x << " ";
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

void insertElement(int arr[], int &n, int pos, int val) {
    // shift elements to the right
    for(int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // insert new value
    arr[pos] = val;

    // increase size
    n++;
}

int main() {
    int arr[100];  // extra space for insertion
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int pos, val;
    cin >> pos >> val;


    if(pos < 0 || pos > n) {
        cout << "Invalid position!" << endl;
        return 0;
    }

    insertElement(arr, n, pos, val);

    cout << "Array after insertion: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}
*/