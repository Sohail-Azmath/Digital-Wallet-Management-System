#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> a, pair<int,int> b)
{
    return a.second < b.second;
}
int main() {
    // your code goes here
    int n,i,j;
    cin>>n;
    vector<pair<int,int>>final;
    map<int,int> mp;
    map<int,int> res;
    vector<string> vec;
    int uid,bal;
    
    for(i=0;i<n;i++)
    {
        cin>>uid>>bal;
        mp[uid]=bal;
    }
    int t;
    cin>>t;
    int arr[t][3];
    for(i=0;i<t;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>arr[i][j];
        }
    }
    for(i=0;i<t;i++)
    {
       int key= arr[i][0];
       if(mp.find(key)!=mp.end())
       {
           if(mp[key] > arr[i][2])
           {
               int x= mp[key] - arr[i][2];
               res[key]=x;
               mp[key]=res[key];
               int y= arr[i][1];
               res[y]=mp[y]+arr[i][2];
               mp[y]=res[y];
               vec.push_back("Success");
           }
           else
           {
               vec.push_back("Failure");
           }
       }
    }
    for( auto i: res)
    {
        final.push_back(i);
    }
    sort(final.begin(),final.end(),comp);
    for( auto i : vec)
    {
        cout<<i<<'\n';
    }
    cout<<'\n';
    for(auto i : final)
    {
        cout<<i.first<<" "<<i.second<<'\n';
    }
    return 0;
}

