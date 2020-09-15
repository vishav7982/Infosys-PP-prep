#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int  b)
{
    if(a==0)
    {
        return b;
    }
    return gcd(b%a,a);
}

int main()
{
    int num1,den1,num2,den2;
    cin>>num1>>den1>>num2>>den2;

    int num3 ,den3;
    den3 = (den1*den2)/__gcd(den1,den2);

    num3 = num1*(den3)/den1 + num2*(den3)/den2;

    ///now we have to reduce P/q until they have no common factor

    int common = __gcd(num3,den3);
    num3 = num3/common;
    den3 = den3/common;
    cout<<num3<<" "<<den3<<"\n";
}
