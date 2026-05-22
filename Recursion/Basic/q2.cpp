#include<bits/stdc++.h>
void fun(int n)
{
    if(n == 1)
    {
      std :: cout << n << " ";
      return;   
    }
    
    fun(n - 1); 
      std :: cout << n << " ";
       
}

int main()
{
  fun(5);
}