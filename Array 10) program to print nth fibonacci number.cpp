#include<bits/stdc++.h>

using namespace std;

///time complexity = O(2^n)
///space complexity = O(n) (of recursive tree )
int fib_recur(int n)
{
    if(n<=1)
    {
        return 1;
    }
    return fib_recur(n-1)+fib_recur(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<fib_recur(n)<<"\n";
    //iterative;
    //time complexity = O(n)
    //space complexity = O(n)
    long long int arr[n+1];
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    cout<<arr[n]<<"\n";
}
