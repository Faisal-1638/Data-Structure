#include <bits/stdc++.h>
using namespace std;

#define mxsz 10
int arr[mxsz], topPos = -1;

void Push(int item)
{
    if(topPos == mxsz - 1)
    {
        cout << "overflow\n";
        return;
    }
    arr[++topPos] = item;
}

void Pop()
{
    if(topPos == -1)
    {
        cout << "underflow\n";
        return;
    }
    topPos--;
}

int Top()
{
    if(topPos == -1)
    {
        cout << "empty stack\n";
        return -1;
    }
    return arr[topPos];
}

void Show()
{
    for(int i = 0; i <= topPos; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Permanently reverse the stack
void ReverseStack()
{
    int l = 0, r = topPos;
    while(l < r)
    {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

int main()
{
    Push(5);
    Push(2);
    Push(3);
    Push(4);

    cout << "Original stack (top to bottom): ";
    Show();
    cout << "Before reverse TOP: " << Top() << "\n";
    ReverseStack();
    cout << "Reversed stack (top to bottom): ";
    Show();
     cout << "After reverse TOP: " << Top() << "\n";


    return 0;
}

/*
Normal approach : Only reverse the stack using top and pop.

#include <bits/stdc++.h>
using namespace std;

#define mxsz 10
int arr[mxsz], topPos = -1;

void Push(int item)
{
    if(topPos == mxsz - 1)
    {
        cout << "overflow\n";
        return;
    }
    arr[++topPos] = item;
}

void Pop()
{
    topPos--;
}

int Top()
{
    return arr[topPos];
}

void Show()
{
    while(topPos!= -1)
    {
        cout << arr[topPos] << " ";
        Pop();

    }
    cout << endl;
}


int main()
{
    Push(5);
    Push(2);
    Push(3);
    Push(4);

    Show();
    


    return 0;
}
*/