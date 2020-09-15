/*
   Many methods to check if linked list is a palindrome or not
   1) get length n . store elements upto n/2 and then pop elements from stack if they are same
   if stack is empty at the end then it is palindrome
   2) traverse upto middle element and then reverse remaining linked list and check if the elements are same
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
    ///function to check whether a linked list is a palindrome or not
    ///Method 1;
    ///time complexity = O(n)
    ///space complexity = O(n)
    bool isPal()
    {
        stack<int> st;
        Node* temp = head;
        Node* mid = middle();
        int len = length();
        bool flag =0;
        if(len&1)
        {
            flag=1;
        }
        while(temp!=mid)
        {
            st.push(temp->data);
            temp=temp->next;
        }
        if(flag ==1)
        {
            st.push(temp->data);
        }
        while(temp!=NULL && !st.empty())
        {
            if(temp->data  == st.top())
            {
                st.pop();
            }
            temp =temp->next;
        }
        if(st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ///get the middle node
    Node* middle()
    {
        Node* slow =head;
        Node* fast = head;
        while(fast!=NULL && fast->next !=NULL)
        {
            fast = fast->next->next;
            slow=slow->next;
        }
        return slow;

    }
    int length()
    {
        Node* temp =head;
        int count =0;
        while(temp !=NULL)
        {
            count++;
            temp=temp->next;
        }
        return count;
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
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.insert(20);
    ll.insert(10);
    if(ll.isPal())
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"No\n";
    }
}
