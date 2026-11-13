// -> Given an array “nums” of size “N” - find the total number of pairs(i,j) [i<j] such that nums[i] + nums[j] = target

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    unordered_map<int,int> mp;
    int result=0;
    for(int j=0;j<n;j++)
    {
        int rem_sum= target-nums[j];
        if(mp.find(rem_sum)!=mp.end())
        {
            result+=mp[rem_sum];

        }
        mp[nums[j]]+=1;
    }
   cout<< result;
}