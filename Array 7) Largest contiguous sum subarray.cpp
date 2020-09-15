
/*
    Kadane's algorithm is used for finding largest sum
    contiguous subarray
*/
#include<bits/stdc++.h>
using namespace std;
//time complexity = O(n)
int kadane(int arr[],int n)
{
    int max_so_far=INT_MIN;
    int max_ending_here=INT_MIN;
    for(int i=0;i<n;i++)
    {
        max_ending_here +=arr[i];
        if(max_so_far<max_ending_here)
        {
            max_so_far=max_ending_here;
        }
        if(max_ending_here<0)
        {
            max_ending_here=0;
        }
    }
    return max_so_far;
}

//to print subarray with maximum sum
void print(int arr[],int n)
{
    int max_so_far=INT_MIN;
    int max_ending_here=INT_MIN;
    int st =0,end=0,temp=0;
    for(int i=0;i<n;i++)
    {
        max_ending_here +=arr[i];
        if(max_so_far<max_ending_here)
        {
            st =temp;
            end=i;
            max_so_far=max_ending_here;
        }
        if(max_ending_here<0)
        {
            max_ending_here=0;
            temp =i+1;
        }
    }
    for(int i=st;i<=end;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<kadane(arr,n)<<"\n";
    print(arr,n);
}
