#include<bits/stdc++.h>

using namespace std;

///three methods :1) sort and find second largest
///2) find the largest element in one traversal and find the 2nd largest
///element in 2nd traversal
///3) find both in one traversal


//time complexity : O(nlogn)
int first_method(int arr[],int n)
{
    if(n<2)
    {
        return -1;
    }
    sort(arr,arr+n);
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i] != arr[n-1])
        {
            return arr[i];
        }
    }
    return -1; ///no 2nd largest element
}

//time complexity - O(2*n)
int second_method(int arr[],int n)
{
    int first =0;
    int second =0;
    for(int i=0;i<n;i++)
    {
        first = max(arr[i],first);
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]<first)
        {
            second = max(arr[i],second);
        }
    }
    return second;
}

//time complexity = O(n)

int third_method(int arr[],int n)
{
    int first =0;
    int second=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>first)
        {
            second = first;
            first = arr[i];
        }
        else if(arr[i]>second && first !=arr[i])
        {
            second = first;
            first = arr[i];
        }
    }
    if(second !=0)
    {
        return second;
    }
    return -1;
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
    cout<<first_method(arr,n)<<"\n";
    cout<<second_method(arr,n)<<"\n";
    cout<<third_method(arr,n)<<"\n";
}
