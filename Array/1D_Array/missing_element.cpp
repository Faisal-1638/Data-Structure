#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v= {1,2,3,4,5,6,7,9,10};
    int n = v.size() + 1;

    int sum = 0;

     for(int i = 0; i < n-1; i++)
     {
        sum += v[i];
     }

     //int sum = accumulate(v.begin(), v.end(), 0);//use it without loop

     long long expsum = n * (n+1) / 2;

     cout << expsum - sum;

return 0;


}

//Time complexity O(1)