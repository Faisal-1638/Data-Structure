#include <bits/stdc++.h>
using namespace std;

void even(vector<int>&v, int i)
{
    if(i == v.size())
    return;
   
    even(v, i + 1);
    if(i % 2 == 0)
     cout << v[i] << " ";
}
int main()
{
   int N;
   cin >> N;
   vector<int> v(N);
   for(int i = 0; i < N; i++)
   {
    cin >> v[i];
   }

   even(v, 0);

    return 0;
}