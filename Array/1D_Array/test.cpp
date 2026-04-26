#include<bits/stdc++.h>
using namespace std;
int main()
{
    string t = "abbbbbabac";

    string s = "abac";

    int m = t.size();
    int n = s.size();

    int indx = -1, compare = 0;
    for(int i = 0; i <= m - n; i++)
    {
        int j;
        for(j = 0; j < n; j++)
        {
            compare++;

            if(t[i+j] != s[j])
            {
                break;
            }
        }

        if(j == n)
        {
            indx = i;
            break;
        }
    }

    cout << indx << endl;
    cout << compare << endl;
    return 0;
}