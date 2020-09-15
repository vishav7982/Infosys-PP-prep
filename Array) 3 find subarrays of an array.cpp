/*
   two methods : one is iterative and other is by using
   recursion
*/

#include<bits/stdc++.h>

using namespace std;

///recursive approach
///time complexity = O(n^2)
void print(vector<int> arr,int start,int end)
{
    if(end == arr.size())
    {
        return;
    }
    else if(start > end)
    {
        print(arr,0,end+1);
    }
    else
    {
        for(int i =start;i<end;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<arr[end]<<"\n";
        print(arr,start+1,end);
    }
    return;
}


///iterative approach
///time complexity = O(n^3)
void printI(vector<int> arr)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int k=i;k<=j;k++)
            {
                cout<<arr[k]<<" ";
            }
            cout<<"\n";
        }
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    ///using recursion
    print(arr,0,0);
    printI(arr);
}
