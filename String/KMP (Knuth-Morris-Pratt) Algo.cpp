#include <iostream>
#include <vector>
#include <string>
using namespace std;

void computeLPS(string pattern, vector<int>& lps) {
    int len = 0;
    int i = 1;

    lps[0] = 0;

    while (i < pattern.length()) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps(m);
    computeLPS(pattern, lps);

    int i = 0; // text index
    int j = 0; // pattern index

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i]) {

            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    KMPSearch(text, pattern);

    return 0;
}

/*
Time Complexity
LPS Construction: O(m)
Pattern Search: O(n)
Total: O(n + m)

Quick Viva Answer
Algorithm	  Main Idea	                  Worst Time
Naive	Compare pattern at every position	O(nm)
Rabin-Karp	Compare hash values first	    O(nm)
KMP	Use LPS array to avoid rechecking	    O(n+m)

Which limitation is overcome?

Rabin-Karp overcomes the excessive character comparisons of Naive using hashing.
KMP overcomes the hash collision problem of Rabin-Karp and the repeated comparisons of Naive using the LPS array.
*/