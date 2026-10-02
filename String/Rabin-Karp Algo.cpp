#include <iostream>
#include <string>
using namespace std;

#define d 256

void rabinKarp(string text, string pattern, int q) {
    int n = text.length();
    int m = pattern.length();

    int p = 0; // Pattern hash
    int t = 0; // Text window hash
    int h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {

        if (p == t) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
                cout << "Pattern found at index " << i << endl;
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t += q;
        }
    }
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABC";

    int q = 101; // Prime number

    rabinKarp(text, pattern, q);

    return 0;
}

/*
Time Complexity
Average Case: O(n + m)
Worst Case: O(n × m) (due to hash collisions)
*/