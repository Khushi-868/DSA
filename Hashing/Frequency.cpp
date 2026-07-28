#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> freq(100, 0);
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(int i=0;i<100;i++){
        if(freq[i]>0){
            cout<<i<<" "<<freq[i]<<endl;
        }
    }
    return 0;
}