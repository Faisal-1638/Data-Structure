#include <bits/stdc++.h>
using namespace std;

int main() {
     int n,q;
     cin >> n >> q;

    vector<long long> a(n), pre(n, 0);

    for(int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    pre[0] = a[0];
    for(int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }

    for(int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        long long sum;
        if(l == 0)
        {
            sum = pre[r];
        }
        else
        {
            sum = pre[r] - pre[l - 1];
        }
        
           cout << sum << "\n";
    }

    return 0;
}
/*
3. Complexity analysis
- Building the prefix sum array: \(O(n)\)
- Answering each query: \(O(1)\)
- Answering all \(q\) queries: \(O(q)\)
- Total time complexity: \(O(n+q)\)

- Space complexity: \(O(n)\)

*/

/*
1 based index

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<long long> a(n + 1);
    vector<long long> pref(n + 1, 0);

    // Input array (1-based)
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    while(q--)
    {
        int l, r;
        cin >> l >> r;

        long long rangeSum = pref[r] - pref[l - 1];

        cout << rangeSum << '\n';
    }

    return 0;
}

// Brute force approach
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while(q--) {
        int l, r;
        cin >> l >> r;

        long long sum = 0;

        for(int i = l; i <= r; i++) {
            sum += a[i];
        }

        cout << sum << "\n";
    }

    return 0;
}

3. Brute force vs. prefix sum
Feature	Brute force	Prefix sum
Preprocessing	\(O(1)\)	\(O(n)\)
One query	\(O(n)\) worst case	\(O(1)\)
All \(q\) queries	\(O(nq)\) worst case	\(O(n+q)\)
Extra space	\(O(1)\) beyond array	\(O(n)\) for prefix array
*/

