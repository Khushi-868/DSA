#include <bits/stdc++.h>
using namespace std;

// Question:
// Given an array nums and two lengths firstLen and secondLen,
// find the maximum sum of two non-overlapping subarrays.
//
// The two subarrays can occur in either order:
// 1. firstLen on LEFT + secondLen on RIGHT
// 2. secondLen on LEFT + firstLen on RIGHT

long long solve(vector<int>& nums, int leftLen, int rightLen)
{
    int n = nums.size();

    // Prefix Sum
    // p[i] = sum of first i elements
    vector<long long> p(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        // Your code
        p[i+1]=p[i]+nums[i];
    }

    long long bestLeft = 0;
    long long ans = 0;

    // Stick / Partition
    // LEFT | RIGHT
    //
    // left side needs leftLen elements
    // right side needs rightLen elements

    for (int i = leftLen; i <= n - rightLen; i++)
    {
        // 1. Find current leftLen-length subarray
        // 2. Update bestLeft
        // 3. Find current rightLen-length subarray
        // 4. Combine bestLeft + rightSum
        // 5. Update ans

        // Your code
        long long curr_left= p[i]-p[i-leftLen];
        bestLeft=max(curr_left,bestLeft);
        long long curr_right=p[i+rightLen]-p[i];
        long long  g1=bestLeft+curr_right;
        ans=max(ans,g1);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int firstLen, secondLen;
    cin >> firstLen >> secondLen;

    // Case 1:
    // firstLen on LEFT
    // secondLen on RIGHT

    long long ans1 = solve(nums, firstLen, secondLen);

    // Case 2:
    // secondLen on LEFT
    // firstLen on RIGHT

    long long ans2 = solve(nums, secondLen, firstLen);

    cout << max(ans1, ans2);

    return 0;
}