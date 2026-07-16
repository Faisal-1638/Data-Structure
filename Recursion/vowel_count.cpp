#include <bits/stdc++.h>
using namespace std;

int countVowel(string s, int i)
{
    if( i == s.size())
     return 0;
    int c = countVowel(s, i + 1);
    char ch = tolower(s[i]);

    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        c = c + 1;
    }

    return c;

}
int main() 
{
    string s;
    getline(cin, s);

    cout << countVowel(s, 0);

    return 0;

}

/*
countVowels("cat",0)
= 0 + countVowels("cat",1)   // c is not vowel
= 1 + countVowels("cat",2)   // a is vowel
= 0 + countVowels("cat",3)   // t is not vowel
= 0                          // base case

Total = 1

Time Complexity: O(n)
Space Complexity (recursion stack): O(n)
*/