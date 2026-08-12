/*
Kadane's Algorithm
Maximum Sum of Two Non-Overlapping Subarrays
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ------------------------------------------------------------
// Function to calculate maximum subarray sum ending at each index
// p[i] = Maximum subarray sum that ENDS exactly at index i
// ------------------------------------------------------------
vector<int> prefixSum(vector<int> &b)
{
    int n = b.size();

    // Stores maximum subarray ending at every index
    vector<int> p(n, 0);

    // Base case
    p[0] = b[0];

    for (int i = 1; i < n; i++)
    {
        // Either start a new subarray from b[i]
        // or extend the previous subarray
        p[i] = max(b[i], p[i - 1] + b[i]);

        // Allow empty subarray (sum = 0)
        p[i] = max(p[i], 0);
    }

    return p;
}

// ------------------------------------------------------------
// Function to calculate maximum subarray sum starting at each index
// s[i] = Maximum subarray sum that STARTS exactly at index i
// ------------------------------------------------------------
vector<int> suffixSum(vector<int> &b)
{
    int n = b.size();

    vector<int> s(n, 0);

    // Base case
    s[n - 1] = b[n - 1];

    // Traverse from right to left
    for (int i = n - 2; i >= 0; i--)
    {
        // Either start from current element
        // or extend the subarray starting at i+1
        s[i] = max(s[i + 1] + b[i], b[i]);

        // Allow empty subarray
        s[i] = max(s[i], 0);
    }

    return s;
}

// ------------------------------------------------------------
// Function to calculate maximum sum of two non-overlapping subarrays
// ------------------------------------------------------------
int maxTwoNonOverlappingSubarraysSum(vector<int> &b)
{
    int n = b.size();
     
    if (n == 0) return 0;

    // Kadane from left
    vector<int> p = prefixSum(b);

    // Kadane from right
    vector<int> s = suffixSum(b);

    // maxprefix[i] =
    // Best subarray sum anywhere from index 0 to i
    vector<int> maxprefix(n, 0);

    // maxsuffix[i] =
    // Best subarray sum anywhere from index i to n-1
    vector<int> maxsuffix(n, 0);

    // Build maxprefix
    maxprefix[0] = p[0];

    for (int i = 1; i < n; i++)
    {
        maxprefix[i] = max(maxprefix[i - 1], p[i]);
    }

    // Build maxsuffix
    maxsuffix[n - 1] = s[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        maxsuffix[i] = max(maxsuffix[i + 1], s[i]);
    }

    // Try every possible split
    // Left subarray ends at or before i
    // Right subarray starts at or after i+1
    int ans = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int currentSum = maxprefix[i] + maxsuffix[i + 1];
        ans = max(ans, currentSum);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    // Read array
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Maximum sum of two non-overlapping subarrays: "
         << maxTwoNonOverlappingSubarraysSum(nums);

    return 0;
}