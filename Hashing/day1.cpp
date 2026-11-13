#Check if there are any two equal numberrs in an array at a distance of k from each other
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    map<int, int> mp;
    for(int i=0;i<n;i++){
        int arr[i];
        cin>>arr[i];
        if(mp.find(arr[i])!=mp.end() && i-mp[arr[i]]<=k){
            cout<<"Yes"<<endl;
            return 0;
        }
        mp[arr[i]] = i;
    }
    cout<<"No"<<endl;
    return 0;
}