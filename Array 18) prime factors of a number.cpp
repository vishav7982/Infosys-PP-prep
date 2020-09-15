#include<bits/stdc++.h>

using namespace std;
///time complexity = O(sqrt(n))
void brute_force(int n)
{
    while(n%2 ==0)
    {
        cout<<"2 ";
        n=n/2;
    }
    for(int i=3;i<=sqrt(n);i+=2)
    {
        while(n%i ==0)
        {
            cout<<i<<" ";
            n=n/i;
        }
    }
    if(n>2)
    {
        cout<<n<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    brute_force(n);
    cout<<"\n";
    /// by using sieve of eratosthenes
    ///once sieve is built we get prime factorization in O(logn)
    ///to build sieve time complexity = O(nloglogn)
    ///space complexity = O(n)
    int spf[n+1];
    spf[1]=1;
    for(int i=2;i<n+1;i++)
    {
        spf[i]=i;
    }
    for(int i=4;i<n+1;i+=2)
    {
        spf[i]=2;
    }
    for(int i=3;i*i<n+1;i++)
    {
        if(spf[i]==i)
        {
            for(int j=i*i;j<n+1;j+=i)
            {
                if(spf[j]==j)
                {
                    spf[j]=i;
                }
            }
        }
    }
    vector<int> prime_factorization;
    while(n!=1)
    {
        prime_factorization.push_back(spf[n]);
        n=n/spf[n];
    }
    for(int i=0;i<prime_factorization.size();i++)
    {
        cout<<prime_factorization[i]<<" ";
    }
    return 0;
}
