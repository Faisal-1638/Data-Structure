#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Create an unordered_map
    // key = int
    // value = string
    unordered_map<int, string> mp;


    // =========================
    // 1. INSERT
    // =========================

    mp[101] = "Rahim";
    mp[102] = "Karim";
    mp[103] = "Hasan";

    // Another way to insert
    mp.insert({104, "Faisal"});


    // =========================
    // 2. ACCESS VALUE
    // =========================

    cout << mp[101] << endl;
    // Rahim


    // =========================
    // 3. FIND
    // =========================

    int key = 102;

    if (mp.find(key) != mp.end())
    {
        cout << "Key found" << endl;
        cout << "Value = " << mp[key] << endl;
    }
    else
    {
        cout << "Key not found" << endl;
    }


    // =========================
    // 4. COUNT
    // =========================

    if (mp.count(103))
    {
        cout << "103 exists" << endl;
    }


    // =========================
    // 5. PRINT ALL
    // =========================

    cout << "\nAll elements:\n";

    for (auto x : mp)
    {
        cout << x.first << " -> " << x.second << endl;
    }


    // =========================
    // 6. ERASE
    // =========================

    mp.erase(102);

    cout << "\nAfter deleting 102:\n";

    for (auto x : mp)
    {
        cout << x.first << " -> " << x.second << endl;
    }


    // =========================
    // 7. SIZE
    // =========================

    cout << "\nSize = " << mp.size() << endl;


    // =========================
    // 8. EMPTY
    // =========================

    if (mp.empty())
    {
        cout << "Map is empty" << endl;
    }
    else
    {
        cout << "Map is not empty" << endl;
    }


    // =========================
    // 9. CLEAR
    // =========================

    mp.clear();

    cout << "Size after clear = "
         << mp.size() << endl;


    return 0;
}