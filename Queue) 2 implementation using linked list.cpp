#include<bits/stdc++.h>
using namespace std;

class Qnode{
public:
    int data;
    Qnode* next;
    Qnode(int d)
    {
        data=d;
        next=NULL;
    }
};

class Queue{
public:
   Qnode *front,*rear;
   Queue()
   {
       front = rear = NULL;
   }
   void enqueue(int data)
   {
       Qnode* temp = new Qnode(data);
       if(rear == NULL)
       {
           front = rear=temp;
           return;
       }
       else
       {
           rear->next = temp;
           rear = temp;
       }
   }
   void dequeue()
   {
       if(front == NULL)
       {
           return;
       }
       Qnode* temp =front;
       front = front->next;
       delete(temp);
       if(front == NULL)
       {
           rear =NULL;
       }
   }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<(q.front)->data<<" ";
    cout<<(q.rear)->data<<" ";
}
