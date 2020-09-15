
/*
  there are two methods to reverse a linked list
  1) iterative
  2) recursive
*/

#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next ;
    Node(int d)
    {
        data=d;
        next = NULL;
    }
};

struct LinkedList
{
    Node* head;
    LinkedList()
    {
        head = NULL;
    }
    int middle()
    {
        Node* slow =head;
        Node* fast = head;
        while(fast!=NULL && fast->next !=NULL)
        {
            fast = fast->next->next;
            slow=slow->next;
        }
        return slow->data;

    }
    void print()
    {
        Node* temp =head;
        while(temp !=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void insert(int data)
    {
        ///at start of linked list
        Node* temp = new Node(data);
        temp->next = head;
        head= temp;
    }
};

int main()
{
    LinkedList ll;
    ll.insert(5);
    ll.insert(4);
    ll.insert(3);
    ll.insert(2);
    ll.insert(1);
    ll.print();
    cout<<"\n";
    cout<<ll.middle();
}

