#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;

    ///using substr function
    for(int i=0;i<s.length();i++)
    {
        for(int len =1;len<=s.length()-i;len++)
        {
            cout<<s.substr(i,len)<<"\n";
        }
    }
    ///without using inbuilt function
    for(int len=1;len<=s.length();len++)
    {
        for(int i =0;i<=s.length()-len;i++)
        {
            int j=i+len-1;
            for(int k=i;k<=j;k++)
            {
                cout<<s[k];
            }
            cout<<"\n";
        }
    }
}
