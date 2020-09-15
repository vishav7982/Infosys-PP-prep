#include<bits/stdc++.h>

using namespace std;

class Graph
{
    int v;
    list<int> *adj;
    public:
        Graph(int v)
        {
            this->v=v;
            adj = new list<int>[v];
        }
        void addEdge(int u,int v)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ///time complexity : O(v+e)
        ///space complexity:O(v)
        void dfs()
        {
            bool visited[v]={false};
            stack<int> st;
            st.push(0); //push source node
            while(!st.empty())
            {
                int temp = st.top();
                st.pop();
                if(!visited[temp])
                {
                    cout<<temp<<" ";
                    visited[temp]=true;

                }
                list<int>::iterator it = adj[temp].begin();
                for(it ;it!=adj[temp].end();it++)
                {
                    if(!visited[*it])
                    {
                        st.push(*it);
                    }
                }
            }
        }
        //O(v+e) - time complexity
        //o(v) - space complexity
        void bfs()
        {
            bool visited[v]={false};
            queue<int> q;
            q.push(0); //push source node
            while(!q.empty())
            {
                int t = q.front();
                q.pop();
                visited[t]=true;
                cout<<t<<" ";
                list<int>::iterator it =adj[t].begin();
                for(it;it!=adj[t].end();it++)
                {
                    if(!visited[*it])
                    {
                        q.push(*it);
                        visited[*it]=true;
                    }
                }
            }
        }

};

int main()
{
    Graph g(5); // Total 5 vertices in graph
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.dfs();
    cout<<"\n";
    g.bfs();

}
