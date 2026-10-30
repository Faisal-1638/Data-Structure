#include<bits/stdc++.h>
int fib(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    int x = fib( n -1) + fib(n - 2);
    return x;     
}

int main()
{
 std:: cout <<  fib(4);
}