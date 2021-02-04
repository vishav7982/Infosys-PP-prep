/*
questions : 
 There is a tree with n nodes and n-1 edges. Two integers u and v are given.
 We need to find the number of valid unordered pairs. The definition for a pair to be 
 valid is given as follows: A pair {x,y} is valid if, in the shortest path from x to y, 
 if both u and v are present then in this path v must come before u. If u or v or both 
 are not present in the path then the pair is valid. 


Sample:

Input: n=3, u=1, v=3  edges were 1<->2,  2<->3
Output:5


solution : tree can be represented as undirected graph
we can use modified bfs to count the pair of 
*/

#include<bits/stdc++.h>

using namespace std;
bool BFS(vector<int> adj[], int src, int dest, int v,
         int pred[], int dist[])
{
    list<int> queue;
    bool visited[v+1];

    for (int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);
                if (adj[u][i] == dest)
                    return true;
            }
        }
    }
 
    return false;
}
vector<int> path(vector<int> adj[],int s,int dest,int v)
{
    int pred[v], dist[v];
    vector<int> path;
    if (BFS(adj, s, dest, v, pred, dist) == false) {
        return path;
    }
    int crawl = dest;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
    return path;
}

int check(vector<int> p ,int a,int b,int count)
{
    if(p.size()==0)
            {
                return count;
            }
            bool flag1 =0;
            bool flag2 =1;
            for(int k = p.size()-1;k>=0;k--)
            {
                if(p[k]==a)
                {
                    flag1=1;
                }
                if(p[k]==b && flag1 ==1)
                {
                    flag2 =0;
                }
            }
            if(flag2)
            {
                count++;
            }
            return count;
}

int main()
{
    int n;
    cin>>n;
    int v=2; //edges
    int a =0,b =2;
    vector<int> adj[n];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    int count =0;
    for(int i =0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            vector<int> p =  path(adj,i,j,n);
            count = check(p,a,b,count);
            vector<int> q = path(adj,j,i,n);
            count = check(q,a,b,count);
        }
    }
    cout<<count<<"\n";
