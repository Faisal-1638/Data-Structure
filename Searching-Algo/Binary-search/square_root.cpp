//Using Binary Search - O(lowg(n)) Time and O(1) Space
#include <iostream>
using namespace std;

int Sqrt(int n){
  
    // initial search space
    int low = 1, high = n;
    int res = 1;
    
    while(low <= high) {
        int mid = low + (high - low)/2;        
        // if square of mid is less than or equal to n 
        // update the result and search in upper half
        if(mid*mid <= n) {
            res = mid;
            low = mid + 1;
        }       
        // if square of mid exceeds n, 
      	// search in the lowwer half
        else {
            high = mid - 1;
        }
    }
    
    return res;
}

int main() {
    int n = 81;
    cout << Sqrt(n);
    return 0;
}