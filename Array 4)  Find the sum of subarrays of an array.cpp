#include<bits/stdc++.h>

using namespace std;
///two methods : generate all subarrays and compute their sum
/// O(n) methods by counting no of occurences of each element in subarrays


///first method
///time complexity - O(n^2)
long int sum1(int arr[],int n)
{
    long int result=0;
    for(int i=0;i<n;i++)
    {
        long int temp=0;
        for(int j=i;j<n;j++)
        {
            temp+=arr[j];
            result+=temp;
        }
    }
    return result;
}

///time complexity - O(n)
long int sum2(int arr[],int n)
{
    long int result = 0;
    for(int i=0;i<n;i++)
    {
        result += arr[i]*(i+1)*(n-i);
    }
    return result;
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
    cout<<sum1(arr,n)<<" "<<sum2(arr,n);
}
