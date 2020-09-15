#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }
    int m;
    cin>>m;
    int brr[m];
    int count =0;
    for(int i=0;i<m;i++)
    {
        cin>>brr[i];
        if(mp[brr[i]])
        {
            count++;
        }
    }
    cout<<count<<"\n";
}
