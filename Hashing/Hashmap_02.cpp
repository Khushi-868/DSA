#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
    vector<int> arr={3,2,3,2,4,3};
    unordered_map<int,int> hashmap;
    for(int i=0;i<arr.size();i++){
        hashmap[arr[i]]++;
    }
    int maxFreq=0;
    int ans=0;
    for(auto i:hashmap){
        if(i.second>maxFreq){
            maxFreq=i.second;
            ans=i.first;
        }

    }
    cout<<ans<<" "<<maxFreq<<endl;
} 