#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        int cnt[3] = {0, 0, 0};
        for (int i = 0; i < n; i++) 
        {
            int w; 
            cin >> w;
            cnt[w]++;
        }
        
        int ops = 0;
        
        ops += cnt[0];
        
        int pairs = min(cnt[1], cnt[2]);
        ops += pairs;
        cnt[1] -= pairs;
        cnt[2] -= pairs;
        
        ops += cnt[1] / 3;
        ops += cnt[2] / 3;
        
        cout << ops << "\n";
    }
    return 0;
}
