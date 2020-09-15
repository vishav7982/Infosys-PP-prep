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
    ///function to reverse linked list using iterative method
    ///time complexity = O(n)
    ///space complexity = O(1)
    void reverse_iterative()
    {
        Node* current = head;
        Node* prev = NULL;
        Node* next = NULL;
        while(current !=NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    ///recursive function to reverse a list
    ///time complexity - O(n)
    ///space complexity - O(1)
    void reverse_recursive()
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        Node* rest = reverse_recursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
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
    ll.reverse_iterative();
    ll.print();
    cout<<"\n";
    ll.reverse_recursive();
    ll.print();
}
