#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<string> s(8);

        for(int i = 0; i < 8; i++)
        {
            cin >> s[i];
        }

        bool f = false;

        for(int i = 0; i < 8; i++)
        {
            if(s[i] == "RRRRRRRR")
            {
                f = true;
                break;
            }
        }

        if(f)
         cout << "R" << "\n";

         else 
          cout << "B" << "\n";

    }
    
 return 0;
}