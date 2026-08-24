#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Question:
    // Given an integer array, find two non-overlapping subarrays
    // having the maximum possible combined sum.
    //
    // Both subarrays are allowed to be empty, so their sum can be 0.
    //
    // Example:
    // Input:
    // 7
    // 2 5 -1 2 -10 1 5
    //
    // Output:
    // 14
    //
    // Explanation:
    // [2, 5, -1, 2] = 8
    // [1, 5] = 6
    // Total = 14

    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Your solution here
    vector<long long> p(n), s(n);
    vector<long long> rightBest(n) ,leftBest(n);
    p[0]=max(a[0],a[0]);
    for(int i=1;i<n;i++)
    {
        p[i]=max({p[i-1]+a[i],a[i],0LL});

    }
    leftBest[0]=p[0];
    for(int i=1;i<n;i++)
    {
        leftBest[i]=max(leftBest[i-1],p[i]);
    }
     s[n-1]=max(a[n-1],a[0]);
    for(int i=n-2;i>=0;i--)
    {
        s[i]=max({s[i+1]+a[i],a[i],0LL});

    }
    rightBest[n-1]=s[n-1];
    for(int i=n-2;i>=0;i--)
    {
        rightBest[i]=max(rightBest[i+1],s[i]);
    }
    vector<int> G(n);
    int ans=0;
    for(int i=0;i<n-1;i++)
    {
        G[i]=leftBest[i]+rightBest[i+1];
        ans=max(G[i],ans);
    }
    cout<<ans;




    return 0;
}