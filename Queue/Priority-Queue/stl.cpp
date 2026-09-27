#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;
    //y default, C++ uses a max heap underneath.
    //priority_queue<int, vector<int>, greater<int>> pq; // min heap

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    cout << pq.top() << endl;  // 30

    pq.pop();

    cout << pq.top() << endl;  // 20
}

/*
pq.push(x);    // insert
pq.top();      // highest-priority element
pq.pop();      // remove highest-priority element
pq.empty();    // check empty
pq.size();     // number of elements
*/