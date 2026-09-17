#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Input
    int n;
    cin >> n;

    // Your code here
    vector<long long>A(n);
    long long ans=0;
    for(int i=0;i<n;i++){
        long long  a,b;
        cin>>a>>b;
        A[i]=a-b;
        ans+=b*n-a;
    }
    sort(A.begin(),A.end(),greater<long long>());
    //position=1,2,3,...
    for(int i=0;i<n;i++)
    {
        ans+=A[i]*(i+1);
    }
    cout<<ans;


    return 0;
}