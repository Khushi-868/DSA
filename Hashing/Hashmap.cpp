#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    unordered_map<int,int> hashmap;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        hashmap[arr[i]]++;
    }
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
       int count=hashmap[x];
       cout<<count<<endl;
    }
}