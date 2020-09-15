#include<bits/stdc++.h>
using namespace std;

///we can use hashing for single most frequent word
///but if the problem is to find k most frequent occuring words
///then we have to use trie and min heap

int main()
{
    string file;
    cin>>file;
    stringstream ss(file);
    map<string,int> mp;
    string word;
    while(ss>>word)
    {
        mp[word]++;
    }
    int max=0;
    string freq;
    map<string,int> :: iterator it = mp.begin();
    while(it !=mp.end())
    {
        if(it->second > max)
        {
            max=it->second;
            freq = it->first;
        }
        ++it;
    }
    cout<<freq<<"\n";

}
