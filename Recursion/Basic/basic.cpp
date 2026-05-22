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