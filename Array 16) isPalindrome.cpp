#include<bits/stdc++.h>

using namespace std;

///time complexity of both cases is O(n)

void UsingLib(string s)
{
    string temp = s;
    reverse(s.begin(),s.end());
    if(temp == s)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
}
void UsingCustom(string s)
{
    int i=0;
    int j=s.length()-1;
    bool flag =0;
    while(i<j)
    {
        if(s[i] != s[j])
        {
            flag =1;
            break;
        }
        i++;
        j--;
    }
    if(flag)
    {
        cout<<"NO\n";
    }
    else
    {
        cout<<"YES\n";
    }
}

int main()
{
    string s;
    cin>>s;
    UsingLib(s);
    UsingCustom(s);
}
