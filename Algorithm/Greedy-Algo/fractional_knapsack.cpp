#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;

    return r1 > r2;
}

int main() {

    int n, capacity;
    cin >> n >> capacity;

    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    // Sort according to value/weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0;

    for (int i = 0; i < n; i++) {

        if (capacity == 0)
            break;

        // Take the whole item
        if (items[i].weight <= capacity) {

            totalValue += items[i].value;
            capacity -= items[i].weight;
        }

        // Take a fraction of the item
        else 
        {
            double fraction = (double)capacity / items[i].weight;

            totalValue += items[i].value * fraction;

            capacity = 0;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Maximum Value = " << totalValue << endl;

    return 0;
}
