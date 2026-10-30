#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n), pref(n, 0), freq(n,0);

    for(ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    pref[0] = v[0];
    for(ll i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + v[i];
    }

   
    ll cnt = 0;
    freq[0] = 1;

    for(ll i = 0; i < n; i++)
    {
        ll rem = pref[i] % n;
        if(rem < 0)
        {
            rem += n;
        }

        cnt += freq[rem];

        freq[rem]++;
    }

    cout << cnt;
}


// prefix-sum Approach

/*
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n), pref(n, 0);

    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    pref[0] = v[0];
    for(int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + v[i];
    }

    
    int cnt = 0;

    for(int i = 0; i < n; i++)
    {
        int sm = 0;
        for(int j = i + 1; j < n; j++)
        {
            sm += v[j];
            if(sm % n == 0)
             cnt++;
        }
    }

    cout << cnt;
}
    */