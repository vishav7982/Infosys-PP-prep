/*
   implementation of stack
   TWO WAYS TO IMPLEMENT STACK
   1) USING ARRAYS
   2) USING LINKED LIST
*/

#include<bits/stdc++.h>

using namespace std;

///1) using arrays
#define MAX 1001 ///maximum size of stack

class Stack{
private:
    int top;
public:
    int arr[MAX];
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};
bool Stack::push(int x)
{
    if(top >= (MAX-1))
    {
        cout<<"STACK Overflow";
        return false;
    }
    else
    {
        arr[++top]=x;
        return true;
    }
}

int Stack::pop()
{
    if(top<0)
    {
        cout<<"STACK Underflow";
        return -1;
    }
    else
    {
        int x = arr[top--];
        return x;
    }
}

int  Stack::peek()
{
    if(top<0)
    {
        cout<<"STACk is empty";
        return -1;
    }
    else
    {
        return arr[top];
    }
}
bool Stack::isEmpty()
{
    if(top<0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


///2) using linked list
class StackNode{
public:
    int data;
    StackNode* next;
};

StackNode* newNode(int data)
{
    StackNode* node = new StackNode();
    node->data = data;
    node->next =NULL;
    return node;
}

int isEmpty(StackNode* root)
{
    if(root == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(StackNode** root,int data)
{
    StackNode* Sn = newNode(data);
    Sn->next = *root;
    *root = Sn;
}
int pop(StackNode** root)
{
    if(isEmpty(*root))
    {
        cout<<"Stack Already Empty\n";
        return -1;
    }
    else
    {
        StackNode* temp = *root;
        *(root)=(*root)->next;
        int popped = temp->data;
        free(temp);
        return popped;
    }
}

int peek(StackNode** root)
{
    if(!isEmpty(*root))
    {
        return (*root)->data;
    }
    return -1;
}
int main()
{
    ///linked list implementation
    StackNode* root = NULL;
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    cout<<pop(&root)<<" ";


    ///array implementation
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop();
}
