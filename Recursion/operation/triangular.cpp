#include <bits/stdc++.h>
using namespace std;
void triangle(int n)
{
    if( n == 1)
    {
        cout << "*\n";
        return;
    }

    triangle(n - 1);


    for(int i = 0; i < n; i++)
    {
        cout << "*";
    }
        cout << endl;
    //triangle(n - 1);
}

int main()
{

    triangle(5);

    return 0;
}

/*
*
**
***
****
*****
*/

/*
*****
****
***
**
*
*/