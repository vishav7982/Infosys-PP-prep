/*
1) Let 1 be the starting and ending point for salesman.
2) Construct MST from with 1 as root using Prim’s Algorithm.
3) List vertices visited in preorder walk of the constructed MST and add 1 at the end.
for example : 
The preorder traversal of MST is 1-2-4-3. Adding 1 at
the end gives 1-2-4-3-1 which is the output of this algorithm.
time complexity : O(Elog(V))
*/
#include<bits/stdc++.h>
#define v 5
using namespace std;

int minKey(int key[],bool mstSet[])
{
    int min = INT_MAX,min_i;
    for(int i=0;i<v;i++)
    {
        if(mstSet[i]== false && key[i] < min)
        {
            min = key[i],min_i = i;
        } 
    }
    return min_i;
}
void printMST(int parent[], int graph[V][V])  
{  
    for (int i = 1; i < V; i++)  
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";  
}  
void PrimMSt(int graph[v][v])
{
    int parent[v]; //array to store constructed MST
    int key[v]; //key values stored to pick minimum weight edge to cut
    bool mstSet[v]; //to represent set of vertices include in mst
    for(int i=0;i<v;i++)
    {
        key[i]=INT_MAX;
        mstSet[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int c =0;c<v-1;c++)
    {
        //pick min key from the set of vertices not yet included
        int u = minKey(key,mstSet);
        mstSet[u]=true;
        for(int i =0;i<v;i++)
        {
            if(graph[u][i] && mstSet[i] == false && graph[u][i] < key[i])
            {
                parent[i] =  u;
                key[i]= graph[u][i];
            }
        }
    }
    printMST(parent,graph);
}
int main()
{
    int graph[v][v]={ { 0, 2, 0, 6, 0 },  
                        { 2, 0, 3, 8, 5 },  
                        { 0, 3, 0, 0, 7 },  
                        { 6, 8, 0, 0, 9 },  
                        { 0, 5, 7, 9, 0 } 
                    };
    PrimMSt(graph);
    return 0;
            
}
