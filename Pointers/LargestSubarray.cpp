#include <bits/stdc++.h>
using namespace std;

// Question:
// Given an array of positive integers and an integer K,
// find the largest subarray whose sum <= K.
//
// Example:
// nums = [1,2,3,4,5,6]
// K = 10
// Output: [1,2,3,4]
//
// Brute Force:
// Try every possible subarray and calculate its sum.
// Then keep track of the maximum length subarray
// whose sum <= K.

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // Your brute-force solution here
     int p=0;
     for(int i=0;i<n;i++)
     {
        int r=0;
        for(int j=i;j<n;j++)
        {
           r=r+nums[j];
           if(r<=k)
           {
              int length=j-i+1;
               p=max(p,length);
           }
       }
    }
    cout<<p;



    return 0;
}