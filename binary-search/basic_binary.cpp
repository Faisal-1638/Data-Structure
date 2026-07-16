#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& a, int target) {
    int low = 0;
    int high = a.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] == target)
            return mid;

        else if (a[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    vector<int> a = {2, 5, 8, 12, 16, 23, 38, 56};

    int target;
    cin >> target;

    int index = binarySearch(a, target);

    if (index != -1)
        cout << "Found at index " << index << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}