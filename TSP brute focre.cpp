/*    travelling salesman problem naive approach
Consider city 1 as the starting and ending point. Since the route is cyclic, we can consider any point as a starting point.
Generate all (n-1)! permutations of cities.
Calculate the cost of every permutation and keep track of the minimum cost permutation.
Return the permutation with minimum cost.
time complexity : O(n!)
*/
#include<bits/stdc++.h>
#define v 4
using namespace std;
int TSP(int adj[][v],int s)
{
	vector<int> vertex;
	for(int i=0;i<v;i++)
	{
		if(i!=s)
		{
			vertex.push_back(i);
		}
	}
	int min_path = INT_MAX;
	do{
		int curr_path_wt = 0; // store current path weight 
		//starting point and ending point 
		int k = s;  
		for(int i =0;i<vertex.size();i++)
		{
			curr_path_wt += adj[k][vertex[i]];
			k = vertex[i];
		}
		curr_path_wt +=adj[k][s];
		//update minimum 
		min_path = min(min_path,curr_path_wt);
	}
	while(next_permutation(vertex.begin(),vertex.end()));
	return min_path ;
}

int main()
{
	int adj[][v] = { { 0, 10, 15, 20 },
                       { 10, 0, 35, 25 },
                       { 15, 35, 0, 30 },
                       { 20, 25, 30, 0 } };
	int s =0;
	cout<<TSP(adj,s)<<"\n";
	
}
