#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;

     vector<int> A(N);

        for(int i = 0; i < N; i++)
        {
          cin >> A[i];
        }

        int minimum = *min_element(A.begin(), A.end());
        int freq = 0;

        for(int i=0; i< N; i++)
        {
            if(A[i] == minimum)
             freq++;
        }

        if(freq % 2 != 0)
         cout << "Lucky\n";

         else 
          cout << "Unlucky\n";


          return 0;

}


