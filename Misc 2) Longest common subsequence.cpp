#include<bits/stdc++.h>

using namespace std;

///LCS by recursion

int lcs(string A,string B,int n ,int m)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    if(A[n-1]==B[m-1])
    {
        return 1 + lcs(A,B,n-1,m-1);
    }
    else
        return max(lcs(A,B,n,m-1),lcs(A,B,n-1,m));
}


int main()
{
    string A,B;
    cin>>A>>B;
    int n = A.length();
    int m= B.length();

    cout<<lcs(A,B,n,m)<<"\n";
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if (A[i-1] == B[j-1])
            {
                dp[i][j]=  1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<"Length of LCS By Dp is : "<<dp[n][m];
}

