#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n;
    int target;
    int res=0;
    cin>>n>>target;
    vector<int>ar;
    for(int i=0;i<=n-1;i++){
    	int y;cin>>y; 
    	ar.push_back(y); 
    }
    unordered_map<int,int> mp;
    for(int j=0;j<n;j++)
    {
        int def=target-ar[j];
        if(mp.count(def))  res+=mp[def];
        mp[ar[j]]++;

    }
    cout<<res<<endl;
    return 0;
}