#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (auto item : items) {
        if (W >= item.weight) {
            W -= item.weight;
            totalValue += item.value;
        }
        else {
            totalValue +=
                ((double)item.value / item.weight) * W;
            break;
        }
    }

    return totalValue;
}

int main() {
    vector<Item> items = {
        {60, 10},
        {100, 20},
        {120, 30}
    };

    int W = 50;

    cout << fractionalKnapsack(W, items);
}

/*
Time Complexity
Sorting: O(n log n)
Traversing items: O(n)

Overall:

O(n log⁡n)

*/