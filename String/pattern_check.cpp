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
*/