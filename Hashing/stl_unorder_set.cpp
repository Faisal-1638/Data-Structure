#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Create an unordered_set
    unordered_set<int> s;

    // =========================
    // 1. INSERT
    // =========================

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);

    // Duplicate values are ignored
    s.insert(20);


    // =========================
    // 2. PRINT
    // =========================

    cout << "Elements: ";

    for (int x : s)
    {
        cout << x << " ";
    }

    cout << endl;


    // =========================
    // 3. FIND
    // =========================

    int target = 30;

    if (s.find(target) != s.end())
    {
        cout << target << " is found" << endl;
    }
    else
    {
        cout << target << " is not found" << endl;
    }


    // =========================
    // 4. COUNT
    // =========================

    if (s.count(20))
    {
        cout << "20 exists" << endl;
    }


    // =========================
    // 5. ERASE
    // =========================

    s.erase(20);

    cout << "After deleting 20: ";

    for (int x : s)
    {
        cout << x << " ";
    }

    cout << endl;


    // =========================
    // 6. SIZE
    // =========================

    cout << "Size = " << s.size() << endl;


    // =========================
    // 7. EMPTY
    // =========================

    if (s.empty())
    {
        cout << "Set is empty" << endl;
    }
    else
    {
        cout << "Set is not empty" << endl;
    }


    // =========================
    // 8. CLEAR
    // =========================

    s.clear();

    cout << "Size after clear = " << s.size() << endl;


    return 0;
}