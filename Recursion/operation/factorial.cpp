#include <bits/stdc++.h>
using namespace std;

long long fact(int x)
{
    if(x == 0 || x == 1)
     return 1;

   return x * fact( x - 1);
}

int main() 
{
    int N;
    cin >> N;

    cout << fact(N) << endl;

    return 0;
}

/*
Let's trace the recursion step by step for n = 5.

Function
long long factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}
Call 1
factorial(5)

Since 5 != 0 and 5 != 1, it returns:

5 * factorial(4)

But to calculate this, we must first find factorial(4).

Call 2
factorial(4)

Returns:

4 * factorial(3)
Call 3
factorial(3)

Returns:

3 * factorial(2)
Call 4
factorial(2)

Returns:

2 * factorial(1)
Call 5 (Base Case)
factorial(1)

The condition

if (n == 0 || n == 1)
    return 1;

is true, so it returns:

1

Now the recursion starts unwinding (coming back).

Returning Values
Back to factorial(2)
2 * factorial(1)
= 2 * 1
= 2

Returns 2.

Back to factorial(3)
3 * factorial(2)
= 3 * 2
= 6

Returns 6.

Back to factorial(4)
4 * factorial(3)
= 4 * 6
= 24

Returns 24.

Back to factorial(5)
5 * factorial(4)
= 5 * 24
= 120

Returns 120.

Visual Stack
factorial(5)
└── factorial(4)
    └── factorial(3)
        └── factorial(2)
            └── factorial(1)
                └── return 1

factorial(2) = 2 × 1   = 2
factorial(3) = 3 × 2   = 6
factorial(4) = 4 × 6   = 24
factorial(5) = 5 × 24  = 120

The key idea is:

Recursion keeps calling smaller problems (n-1).
It stops at the base case (n == 1 or n == 0).
Then the answers are multiplied together while returning back up the call stack.
*/
