/*
  use floyd's cycle detection algorithm
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
    bool isLoop()
    {
        Node* slow = head;
        Node* fast = head;
        slow=slow->next;
        fast=fast->next->next;
        while(slow !=NULL && slow!=fast && fast->next != NULL)
        {
            slow  = slow->next;
            fast  =fast->next->next;
        }
        if(slow == fast)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insert(int data)
    {
        ///at start of linked list
        Node* temp = new Node(data);
        temp->next = head;
        head= temp;
    }
    void special_insertion(int data)
    {
        Node* temp = new Node(data);
        Node* tp = head;
        while(tp->next!=NULL)
        {
            tp=tp->next;
        }
        tp->next=temp;
        temp->next = head;
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
    ll.special_insertion(6);
    if(ll.isLoop())
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
}


