/**
Enqueue: Adds an item to the queue.
 If the queue is full,
 then it is said to be an Overflow condition.
Dequeue: Removes an item from the queue.
 The items are popped in the same order in which
  they are pushed. If the queue is empty,
  then it is said to be an Underflow condition.

**/
#include<bits/stdc++.h>

using namespace std;


class Queue
{
   public:
       int front,rear,size;
       unsigned capacity;
       int* arr;
};
Queue* Create(unsigned capacity)
{
    Queue* que = new Queue();
    que->capacity= capacity;
    que->front = que->size =0;
    que->rear = capacity-1;
    que->arr = new int[(capacity)*sizeof(int)];
    return que;
}

bool isFull(Queue* que)
{
    if(que->size == que->capacity)
    {
        return true;
    }
    return false;
}
bool isEmpty(Queue* que)
{
    if(que->size ==0)
    {
        return true;
    }
    return false;
}
void enqueue(Queue* que,int data)
{
    if(isFull(que))
    {
        return ;
    }
    que->rear = (que->rear +1)%que->capacity;
    que->arr[que->rear]=data;
    que->size +=1;
}

int dequeue(Queue* que)
{
    if(isEmpty(que))
    {
        return -1;
    }
    int item = que->arr[que->front];
    que->front = (que->front + 1)%que->capacity;
    que->size -=1;
    return item;
}

int front(Queue* que)
{
    if(isEmpty(que))
    {
        return -1;
    }
    return que->arr[que->front];
}
int rear(Queue* que)
{
    if(isEmpty(que))
    {
        return -1;
    }
    return que->arr[que->rear];
}

int main()
{
    Queue* que = Create(10);
    enqueue(que,10);
    enqueue(que,20);
    enqueue(que,30);
    enqueue(que,40);
    cout<<front(que)<<" ";
    cout<<rear(que)<<" ";
}
