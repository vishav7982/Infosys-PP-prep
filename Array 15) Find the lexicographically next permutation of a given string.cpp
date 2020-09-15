#include<bits/stdc++.h>
using namespace std;
/// two methods :
///we can use  STL function next_permutation(s.begin(),s.end()) to
///compute lexicographically next string

///

string UsingSTL(string s)
{
    bool val = next_permutation(s.begin(),s.end());
    if(val)
        return s;///returns lexicographically next string
    return s; ///return the same string as it is last string
}


///we can write the code for next_permutation itself

void rev(string& s,int l,int r)
{
    while(l<r)
    {
        swap(s[l++],s[r--]);
    }
}

int binSearch(string& s,int l,int r,char key)
{
    int index=-1;
    while(l<=r)
    {
        int mid = l+(r-l)/2;
        if(s[mid]<=key)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
            if(index==-1 || s[index]>=s[mid])
            {
                index =mid;
            }
        }
    }
    return index;
}
//time complexity = O(n)
bool WithoutSTL(string& s)
{
    int len = s.length();
    int i=len-2;
    while(i>=0 && s[i] >=s[i+1])
    {
        --i;
    }
    if(i<0)
    {
        return false;
    }
    else
    {
        int index=binSearch(s,i+1,len-1,s[i]);
        swap(s[i],s[index]);
        rev(s,i+1,len-1);
        return true;
    }
}

int main()
{
    string s;
    cin>>s;
    if(WithoutSTL(s))
    {
        cout<<s;
    }
    else
    {
        cout<<"No word possible\n";
    }

}
