#include <bits/stdc++.h>
using namespace std;

void reverseString(string s, int i)
{
    if(i < 0)
        return;

    cout << s[i];

    reverseString(s, i - 1);
}

int main()
{
    string s = "HELLO";

    reverseString(s, s.length() - 1);
}

/*
#include <bits/stdc++.h>
using namespace std;

string reverseString(string s)
{
    if(s.empty())
        return "";

    return reverseString(s.substr(1)) + s[0];
}

int main()
{
    string s = "HELLO";

    cout << reverseString(s);
}
*/