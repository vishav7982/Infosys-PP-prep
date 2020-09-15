
#include<bits/stdc++.h>

///method one is to use merge function of merge sort
/// another method is to insert elements as keys in map
/// and print map elements
using namespace std;
///time complexity = O(n+m)
///space complexity = O(n+m);
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int m;
    cin>>m;
    int brr[m];
    for(int i=0;i<m;i++)
    {
        cin>>brr[i];
    }
    int temp[n+m];
    int st=0;
    int i=0;
    int j=0;
    while(i<n && j<m)
    {
        if(arr[i]<brr[j])
        {
            temp[st++]=arr[i++];
        }
        else
        {
            temp[st++]=brr[j++];
        }
    }
    while(i<n)
    {
        temp[st++]=arr[i++];
    }
    while(j<m)
    {
        temp[st++]=brr[j++];
    }
    for(int i=0;i<n+m;i++)
    {
        cout<<temp[i]<<" ";
    }
}
