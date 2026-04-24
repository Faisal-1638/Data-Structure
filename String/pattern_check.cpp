#include <iostream>
using namespace std;

int main()
{
    string text = "programming";                  
    string pattern = "gram";

    int n = text.length();
    int m = pattern.length();

    bool found = false;
    int indx= -1;

    for(int i = 0; i <= n - m; i++)
    {            
        int j;

        for(j = 0; j < m; j++)
        {
            if(text[i + j] != pattern[j])
                break;
        }

        if(j == m)
        {
            found = true;
            indx=i;
            break;
        }
    }

    if(found)
        cout << "Pattern Found At Index "<<indx;
    else
        cout << "Pattern Not Found";

return 0;

}


/*
adding comparison

#include <bits/stdc++.h>
using namespace std;

int main() {
    string T = "cbcddcddcdcccddd";
    string P = "ccd";

    int n = T.length();
    int m = P.length();

    int comparisons = 0;
    int index = -1;

    // Naive pattern matching
    for(int i = 0; i <= n - m; i++) {
        int j;

        for(j = 0; j < m; j++) {
            comparisons++; // count every comparison

            if(T[i + j] != P[j]) {
                break;
            }
        }

        if(j == m) {
            index = i;
            break; // stop at first match
        }
    }

    cout << "First occurrence index: " << index << endl;
    cout << "Total comparisons: " << comparisons << endl;

    return 0;
}
*/
/*
We will explain every variable, every step, and every iteration.

1️⃣ What the variables mean

Assume:

text = "programming"
pattern = "gram"

Lengths:

n = 11
m = 4

Goal: check if pattern exists inside text.

2️⃣ Why the outer loop runs i <= n - m
for(int i = 0; i <= n - m; i++)
n - m = 11 - 4 = 7

So:

i = 0 → 7

Why?

Because pattern length is 4, so it cannot start after index 7.

Example:

programming
01234567890

If pattern starts at 8, we need:

8 9 10 11

But index 11 doesn't exist.

So last valid start = 7.

3️⃣ What i represents

i = starting index of the pattern in the text

Example positions we check:

i = 0
programming
gram

i = 1
programming
 gram

i = 2
programming
  gram

i = 3
programming
   gram
4️⃣ Inner loop
for(j = 0; j < m; j++)

This loop checks each character of the pattern.

Pattern:

gram
0123

So:

j = 0
j = 1
j = 2
j = 3
5️⃣ Character comparison
if(text[i + j] != pattern[j])
    break;

This compares characters.

Example:

text[i + j]
pattern[j]
6️⃣ Example Step-by-Step
i = 0
text:    programming
pattern: gram

Compare:

j = 0
text[0] = p
pattern[0] = g
p != g

Break inner loop.

Move to next i.

i = 1
text[1] = r
pattern[0] = g

Mismatch.

Break.

i = 2
text[2] = o
pattern[0] = g

Mismatch.

Break.

i = 3

Now:

text:    programming
pattern:    gram

Start comparing:

j = 0
text[i+j] = text[3] = g
pattern[0] = g

Match.

j = 1
text[4] = r
pattern[1] = r

Match.

j = 2
text[5] = a
pattern[2] = a

Match.

j = 3
text[6] = m
pattern[3] = m

Match.

Now inner loop ends.

j = 4
7️⃣ Why we check if(j == m)
if(j == m)

m = 4

If j == 4, it means:

all characters matched

So pattern is found.

8️⃣ Pattern found block
found = true;
break;

Set result → pattern exists.

Break outer loop (stop searching).

9️⃣ Visual Diagram
Text:     programming
Index:    01234567890

Pattern:  gram

Sliding pattern:

programming
gram

programming
 gram

programming
  gram

programming
   gram   ✔ MATCH
🔟 Why text[i + j]


We will use the naive pattern matching algorithm and count each character comparison.

🔹 Given
Pattern P="ccd" (length m = 3)
Text T="cbcddcddcdcccddd" (length n = 16)

We slide the pattern one by one and compare left to right.

We count every character comparison, even mismatches.



🔍 Step-by-step matching

Text with indices:

Index:  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
Text :  c b c d d c d d c d c  c  c  d  d  d

Pattern: c c d

🔹 Shift 0 (T[0..2] = "cbc")

Compare:

P[0]=c vs T[0]=c → ✔ (1)
P[1]=c vs T[1]=b → ❌ (2 comparisons used)

❌ mismatch → shift

🔹 Shift 1 (T[1..3] = "bcd")
P[0]=c vs T[1]=b → ❌ (1 comparison)

❌ shift

🔹 Shift 2 (T[2..4] = "cdd")
P[0]=c vs T[2]=c → ✔ (1)
P[1]=c vs T[3]=d → ❌ (2)

❌ shift

🔹 Shift 3 (T[3..5] = "ddc")
P[0]=c vs T[3]=d → ❌ (1)

❌ shift

🔹 Shift 4 (T[4..6] = "dcd")
P[0]=c vs T[4]=d → ❌ (1)

❌ shift

🔹 Shift 5 (T[5..7] = "cdd")
P[0]=c vs T[5]=c → ✔ (1)
P[1]=c vs T[6]=d → ❌ (2)

❌ shift

🔹 Shift 6 (T[6..8] = "ddc")
P[0]=c vs T[6]=d → ❌ (1)

❌ shift

🔹 Shift 7 (T[7..9] = "dcd")
P[0]=c vs T[7]=d → ❌ (1)

❌ shift

🔹 Shift 8 (T[8..10] = "cdc")
P[0]=c vs T[8]=c → ✔ (1)
P[1]=c vs T[9]=d → ❌ (2)

❌ shift

🔹 Shift 9 (T[9..11] = "dcc")
P[0]=c vs T[9]=d → ❌ (1)

❌ shift

🔹 Shift 10 (T[10..12] = "ccc") ⭐
P[0]=c vs T[10]=c → ✔ (1)
P[1]=c vs T[11]=c → ✔ (2)
P[2]=d vs T[12]=c → ❌ (3)

❌ shift

🔹 Shift 11 (T[11..13] = "ccd") ⭐ MATCH FOUND
P[0]=c vs T[11]=c → ✔ (1)
P[1]=c vs T[12]=c → ✔ (2)
P[2]=d vs T[13]=d → ✔ (3)

✔ MATCH FOUND at index 11

📌 Total comparisons

Let’s count:

Shift 0 → 2
Shift 1 → 1
Shift 2 → 2
Shift 3 → 1
Shift 4 → 1
Shift 5 → 2
Shift 6 → 1
Shift 7 → 1
Shift 8 → 2
Shift 9 → 1
Shift 10 → 3
Shift 11 → 3
🔢 Total N:
N = 2 + 1 + 2 + 1 + 1 + 2 + 1 + 1 + 2 + 1 + 3 + 3
  = 20 comparisons
✅ Final Answer
First occurrence index: 11
Total comparisons (N): 20
*/