#include<bits/stdc++.h>
void fun(int n)
{
    if(n == 0) //base case
     return;
    fun(n - 1); // recursive call
    std :: cout << n << " ";
    //fun(n - 1); // recursive call
   
}

int main()
{
  fun(5);
}

/*
Trace for fun(5)
Call Phase
fun(5)
→ fun(4)
  → fun(3)
    → fun(2)
      → fun(1)
        → fun(0)

At fun(0), the base case is reached and it returns.

Return Phase

Now the functions start finishing one by one:

fun(1) prints 1
fun(2) prints 2
fun(3) prints 3
fun(4) prints 4
fun(5) prints 5

Output:

1 2 3 4 5


This is the most important recursion concept. Think of it like a stack of unfinished function calls.

Your code:

void fun(int n)
{
    if(n == 0)
        return;

    fun(n - 1);
    cout << n << " ";
}
Step 1: Calls are made

When you do:

fun(3);

Execution goes:

fun(3)
  fun(2)
    fun(1)
      fun(0)

At this point nothing has been printed yet.

Each function is waiting at this line:

cout << n << " ";

So the stack looks like:

fun(3) waiting
fun(2) waiting
fun(1) waiting
fun(0) running
Step 2: Base case reached

Inside fun(0):

if(n == 0)
    return;

So it returns.

Question: Return to where?

Answer:

👉 Return to the function that called it.

fun(0) was called by fun(1).

So control goes back to:

fun(1)
{
    fun(0);   // finished
    cout << 1 << " ";   // next line executes
}

Prints:

1
Step 3: fun(1) finishes

After printing 1, fun(1) reaches its end.

So it returns to its caller:

fun(2)

Execution resumes after:

fun(1);

So:

cout << 2 << " ";

runs.

Output:

1 2
Step 4: fun(2) finishes

Returns to:

fun(3)

and executes:

cout << 3 << " ";

Output:

1 2 3
Visual Stack
CALLS

fun(3)
 └─ fun(2)
     └─ fun(1)
         └─ fun(0)
             return

RETURNS

fun(1) prints 1
return

fun(2) prints 2
return

fun(3) prints 3
return

Think of it like climbing down stairs:

3
2
1
0  <-- reached bottom

Now you climb back up:

0 -> 1 (print 1)
1 -> 2 (print 2)
2 -> 3 (print 3)

The key idea:

return does not jump to main().
It returns to the exact function call that made the recursive call, and execution continues from the next line after that call.

That's why code after the recursive call executes during the return phase.
*/