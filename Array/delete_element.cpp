#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> v(n);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
      
        int pos;
        cin >> pos;
    
        for(int i = pos; i < n-1; i++)
        {
            v[i] = v[i+1];
        }

          v.pop_back();
          n--;

          for(int x : v)
          {
            cout << x << " ";
          }

    
          return 0;
    
}


/*

#include <iostream>
using namespace std;

void deleteElement(int arr[], int &n, int pos) {
    for(int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

int main() {
    int arr[100], n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int pos;
    cin >> pos;

    if(pos < 0 || pos >= n) {
        return 0;
    }

    deleteElement(arr, n, pos);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
*/