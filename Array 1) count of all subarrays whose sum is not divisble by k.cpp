#include<bits/stdc++.h>

/*
   logic : find the length of longest subarray whose sum is not divisible by k
   use this length as length of sliding window and find the count of subarrays
   whose sum is not divisible by
   time complexity = O(n)
   space  = O(1)
*/
using namespace std;


int countSub(int arr[],int n,int k)
{
    ///first find if the sum of whole array is divisible by k or not
    int sum =0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    if(sum%k)
    {
        return 1;
    }
    ///find the index of first element not divisible by k
    ///find the index of last element not divisible by k
    int first =0;
    while(first<n  && (arr[first]%k ==0) )
    {
        first++;
    }
    int last =n-1;
    while(last>=0 && (arr[last]%k==0))
    {
        last--;
    }
    int length =0;
    sum=0;
    ///all elements are divisible by k
    if(first == n)
    {
        return -1;
    }
    else
    {
        length = max(n-1-first,last);
    }
    int count =0;
    for(int i=0;i<length;i++)
    {
        sum+=arr[i];
    }
    if(sum%k !=0)
    {
        count++;
    }
    for(int i=length;i<n;i++)
    {
        sum+=arr[i];
        sum -=arr[i-length];
        if(sum%k !=0)
        {
            count++;
        }
    }
    return count;
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
    int k;
    cin>>k;
    cout<<countSub(arr,n,k);

}
