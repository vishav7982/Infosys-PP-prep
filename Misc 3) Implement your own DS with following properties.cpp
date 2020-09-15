/*
   Implement a Data Structure that you can do insert()
   delete() search() operations in O(1) time complexity
*/

#include<bits/stdc++.h>

using namespace std;

class DataStuct{
    vector<int> v;
    map<int,int> mp; ///use unordered_map for O(1)
public:
    void insert(int x)
    {
        if(mp[x])
        {
            return;
        }
        int index = v.size();
        v.push_back(x);
        mp[x]=index;
    }
    void remove(int x)
    {
        if( !mp[x])
        {
            return;
        }
        int last = v.size()-1;
        int ind = mp[x];
        swap(v[last],v[ind]);
        v.pop_back();
        mp[v[ind]]=ind;
    }
    int search(int x)
    {
        if(mp[x])
        {
            return mp[x];
        }
        return -1;
    }
};

int main()
{
    DataStuct ds;
    ds.insert(10);
    ds.insert(20);
    ds.insert(30);
    ds.insert(40);
    cout<<ds.search(30)<<"\n";
    ds.remove(30);
    cout<<ds.search(40);
}
