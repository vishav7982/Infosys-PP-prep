/**
   Binary search tree
   left child smaller than parent
   right child greater than parent


   For deletion there are three possible scenarios:
   1)Node to be deleted is leaf:
   2)Node to be deleted has only one child
   3)Node to be deleted has two children:


   For vertical Order traversal
   give root distance as  0 and
   its left as 0 -1 and
   its right as 0+1 and do same in level order manner
   and make a map of horizontal distances and corresponding nodes which have same
   horizontal distance and print them in order of increasing hd


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
    Node* Delete(Node *root,int key)
    {
        if(root == NULL)
        {
            return root;
        }
        if(key<root->data)
        {
            root->left = Delete(root->left,key);
        }
        else if(key > root->data)
        {
            root->right = Delete(root->right,key);
        }
        else
        {
            ///case 1) the node to be deleted is leaf node
            ///and case 2) the node with only one child
            if(root->left == NULL)
            {
                /// delete the node and move its right child to its position
                Node* temp =root->right;
                free(root);
                return temp;
            }
            else if(root->right == NULL)
            {
                Node* temp = root->left;
                free(root);
                return temp;
            }
            ///case 3 : First GEt the Inorder Successor
            Node* temp = MinValNode(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
        return root;
    }
    Node* MinValNode(Node* root)
    {
        Node* temp =root;
        while(temp && temp->left !=NULL)
        {
            temp = temp->left;
        }
        return temp;
    }

    void Inorder(Node* root)
    {
        if(!root)
        {
            return;
        }
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
    void PostOrder(Node *root)
    {
        if(!root)
        {
            return;
        }
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data<<" ";

    }
    void PreOrder(Node *root)
    {
        if(!root)
        {
            return;
        }
        cout<<root->data<<" ";
        PostOrder(root->left);
        PostOrder(root->right);
    }

    ///worst case time complexity = O(n)
    ///space complexity = O(n)
    void LevelOrder(Node *root)
    {
        if(root==NULL)
        {
            return ;
        }
        queue<Node *> q;
        q.push(root);
        while(!q.empty())
        {
            Node* node = q.front();
            cout<<node->data<<" ";
            q.pop();
            if(node->left)
            {
                q.push(node->left);
            }
            if(node->right)
            {
                q.push(node->right);
            }
        }
    }

    void zigzag(Node* root)
    {
        if(root == NULL)
        {
            return ;
        }
        stack<Node* > curLevel;
        stack<Node* > nextlevel;
        curLevel.push(root);
        bool left =true;
        while(!curLevel.empty())
        {
            Node* temp = curLevel.top();
            curLevel.pop();
            if(temp)
            {
                cout<<temp->data<<" ";
                if(left)
                {
                    if(temp->left)
                    {
                        nextlevel.push(temp->left);
                    }
                    if(temp->right)
                    {
                        nextlevel.push(temp->right);
                    }
                }
                else
                {
                    if(temp->right)
                    {
                        nextlevel.push(temp->right);
                    }
                     if(temp->left)
                     {
                        nextlevel.push(temp->left);
                     }
                }
            }
            if(curLevel.empty())
            {
                left = !left;
                swap(curLevel,nextlevel);
            }
        }
    }

    /// time complexity = O(nlogn)
    /// space complexity= O(n)
    void VerticalOrder(Node *root)
    {
        if(root==NULL)
            return;

        map<int,vector<int> > mp;
        int hd=0;
        queue<pair<Node * ,int> > q;
        q.push(make_pair(root,hd));
        while(!q.empty())
        {
            pair<Node *,int> temp = q.front();
            q.pop();
            hd = temp.second;
            Node *node = temp.first;
            mp[hd].push_back(node->data);
            if(node->left)
            {
               q.push({node->left,hd-1});
            }
            if(node->right)
            {
               q.push({node->right,hd+1});
            }
        }
        ///traverse and print map according to horizontal distance hd
        map<int,vector<int> >::iterator it = mp.begin();
        while(it !=mp.end())
        {
           for(int i=0;i<it->second.size();i++)
           {
               cout<<it->second[i]<<" ";
           }
           cout<<"\n";
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
    //BST.Inorder(root);
    //BST.Delete(root,70);
    //BST.LevelOrder(root);
    cout<<"\n\n";
    BST.zigzag(root);
    //BST.VerticalOrder(root);
    return 0;
}
