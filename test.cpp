#include<bits/stdc++.h>
using namespace std;
#define MAX 10
class CircularQueue
{
    private: 
      int arr[MAX];
      int front;
      int rear;

    public:
      CircularQueue()
      {
        front = -1;
        rear = -1;
      }

      void Enqueue(int x)
      {
        if(front == 0 && rear == MAX -1 || rear + 1 == front)
        {
            cout << "Overflow\n";
            return;
        }

        if(front == -1)
        {
            front = rear = 0;
            arr[rear] = x;
        }

        else if(rear == MAX - 1)
        {
         rear = 0;
         arr[rear] = x;
        }

         else
          arr[++rear] = x;
      }

      void Dequeue()
      {
        if(front == -1)
        {
            cout << "Underflow\n";
            return;
        }

        if(front == rear)
          front = rear = -1;

          else if(front == MAX - 1)
          {
            front = 0;
          }

          else
           front++;        
      }

      int Front()
      {
        if(front == -1)
            return -1;
        
        return arr[front];
      }

      int size()
      {
        if(front == -1)
        return 0;
        
        if(rear >= front)
        return rear - front + 1;

        else 
         return MAX - front + rear + 1;
      }


};




int main()
{
    CircularQueue q;
    q.Enqueue(5);
    q.Enqueue(10);
    q.Enqueue(20);

    cout << q.size() << endl;
    cout << q.Front() << endl;

    q.Dequeue();

    while(q.size() != 0)
    {
        cout << q.Front() << " ";
        q.Dequeue();
    }


}