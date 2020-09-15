/**
   Binary search tree
   left child smaller than parent
   right child greater than parent

   ** TOP VIEW is similiar to vertical view except we only print
   one node at a horizontal distace hd

   Two methods :
   1) Do vertical traversal and only push first node with
   horizontal distance hd
   2) In this method, we dont require a queue. here we use two variables,
    one for vertical distance of current node and 2nd is level of current node.
    We use the vertical distance for indexing.
    If one node with the same vertical distance comes
    again, we check if depth of new node is lower or
    higher with respect to the current node with same
    vertical distance in the map. If depth of new
     node is lower, then we replace it.

    **LEFT VIEW
    Two methods:
    1) Simply Do level order traversal and print the first node in every level
    2) The idea is to use recursive traversal and we keep track of maximum level
    reached till now and whenever we reach a level greater than maximum level
    we print that node and increment our maximum level
    (We traverse left subtree before right subtree)

    **Right View
    its similiar to left view
    also two methods same as left
    1) do level order traversal print last node of every level or first push right node into queue then
    left (then find first element of every level)
    2) Same method but we traverse right subtree before left subtree

    ** BOTTOM VIEW
    its similiar to top view
    same method can be used with little modification
    1) do vertical order traversal and keep on updating map with nodes with distance hd
    the last node with distance hd comes last and is only stored in map
    so we can retrieve it from map
    2)In this method, we dont require a queue. here we use two variables,
    one for vertical distance of current node and 2nd is level of current node.
    We use the vertical distance for indexing.
    If one node with the same vertical distance comes
    again, we check if depth of new node is lower or
    higher with respect to the current node with same
    vertical distance in the map. we replace it everytime

**/

#include<bits/stdc++.h>

using namespace std;

class Node{
    int data;
    Node *left,*right;
public:
    Node()
    {
    left = right = NULL;
    }
    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
    Node* Insert(Node *root,int data)
    {
        if(!root)
        {
            return new Node(data);
        }
        if(data > root->data)
        {
            root->right = Insert(root->right,data);
        }
        else
        {
            root->left = Insert(root->left,data);
        }
        return root;
    }
    void TopView(Node *root)
    {
        ///the idea is similiar to vertical order traversal but we only consider only
        ///one node at a distance hd
        if(root == NULL)
        {
            return;
        }
        map<int,int> mp;
        queue<pair<Node* ,int> > q;
        int hd =0;
        q.push({root,hd});
        while(!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();
            hd = temp.second;
            Node *node = temp.first;
            if(mp[hd]==0)
            {
                mp[hd]=node->data;
            }
            if(node->left)
            {
                q.push({node->left,hd-1});
            }
            if(node->right)
            {
                q.push({node->right,hd+1});
            }
        }
        map<int,int> ::iterator it =mp.begin();
        while(it !=mp.end())
        {
            cout<<it->second<<" ";
            ++it;
        }
    }
    ///left View of A binary tree
    //Method -1
    void LeftView(Node * root)
    {
        if(root == NULL)
        {
            return;
        }
        queue<Node * > q;
        q.push(root);
        ///delimeter
        q.push(NULL);
        while(!q.empty())
        {
            Node *temp =q.front();
            if(temp)
            {
                cout<<temp->data<<" ";
            while(q.front()!=NULL)
            {
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
                q.pop();
                temp=q.front();
            }
            q.push(NULL);
        }
        q.pop();
       }
   }
   void util_left(Node* root,int level,int* max_level)
   {
       if(root==NULL)
       {
           return;
       }
       if(*max_level<level)
       {
           cout<<root->data<<" ";
           *max_level = level;
       }
       util_left(root->left,level+1,max_level);
       util_left(root->left,level+1,max_level);
   }
   ///left view -method 2
   void LeftView2(Node *root)
   {
       int max_level = 0;
       util_left(root,1,&max_level);
   }
   ///method 1 - right view
   void rightView1(Node *root)
   {
       if(root == NULL)
       {
           return;
       }
       queue<Node* > q;
       q.push(root);
       while(!q.empty())
       {
           int n=q.size();
           for(int i=1;i<=n;i++)
           {
               Node *temp = q.front();
               q.pop();
               if(i==n)
               {
                   cout<<temp->data<<" ";
               }
               if(temp->left)
               {
                   q.push(temp->left);
               }
               if(temp->right)
               {
                   q.push(temp->right);
               }
           }
       }
   }
   void util_right(Node *root,int level,int* max_level)
   {
       if(root == NULL)
       {
           return;
       }
       if(level > *max_level)
       {
           cout<<root->data<<" ";
           *max_level=level;
       }
       util_right(root->right,level+1,max_level);
       util_right(root->left,level+1,max_level);


   }
   ///method -2 right view
   void rightView2(Node * root)
   {
       int max_level =0;
       util_right(root,1,&max_level);
   }

   /// bottom view
   void BottomView(Node *root)
    {
        ///the idea is similiar to vertical order traversal but we only consider only
        ///one node at a distance hd
        if(root == NULL)
        {
            return;
        }
        map<int,int> mp;
        queue<pair<Node* ,int> > q;
        int hd =0;
        q.push({root,hd});
        while(!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();
            hd = temp.second;
            Node *node = temp.first;
            mp[hd]=node->data;
            if(node->left)
            {
                q.push({node->left,hd-1});
            }
            if(node->right)
            {
                q.push({node->right,hd+1});
            }
        }
        map<int,int> ::iterator it =mp.begin();
        while(it !=mp.end())
        {
            cout<<it->second<<" ";
            ++it;
        }
    }
};
int main()
{
    Node BST,*root =NULL;
    root=BST.Insert(root,50);
    BST.Insert(root, 30);
    BST.Insert(root, 20);
    BST.Insert(root, 40);
    BST.Insert(root, 70);
    BST.Insert(root, 60);
    BST.Insert(root, 80);
    //BST.TopView(root);
    //BST.LeftView(root);
    //BST.LeftView2(root);
    //BST.rightView1(root);
    cout<<"\n";
    //BST.rightView2(root);
    BST.BottomView(root);

    return 0;
}

