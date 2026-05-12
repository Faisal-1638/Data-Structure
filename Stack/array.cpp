#include <bits/stdc++.h>
using namespace std;

#define mxsz 10
int arr[mxsz], topPos = -1;

void Push(int item) 
{
    if(topPos == mxsz - 1)
    {
        cout<<"overflow"<<endl;
        return;
    }
    topPos++;
    arr[topPos] = item;
    //arr[++topPos] = item;
}

void Pop() 
{
    if (topPos == -1)
    {
        cout<<"underflow"<<endl;
        return;
    }
        topPos--;
}

int Top() 
{
    return arr[topPos];
}

int Size()
{
    return topPos+1;
}

void Show() 
{
    for (int i = 0; i <= topPos; i++) 
    {
            cout << arr[i] << " ";
    }
        cout << endl;
}

int main() {
   Push(5);
   Push(2);
   Push(3);
   cout<<"stack : ";
   Show();
   cout<<"top : ";
   cout << Top() << endl;
   Pop();
   cout<<"top after pop: ";
   cout << Top() << endl;
    return 0;
}