#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    map<int,int> mp;
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
        mp[arr[i]]++;
    }
    map<int,int>::iterator it = mp.begin();
    while(it !=mp.end())
    {
        cout<<it->first<<" "<<it->second<<"\n";
        ++it;
    }

}
