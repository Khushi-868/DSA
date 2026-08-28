#include <bits/stdc++.h>
#include <io.h>
using namespace std;

// ============================================================
// QUESTION:
// Find the largest valid substring.
//
// A substring is valid if the difference between ANY pair
// of characters is less than k.
//
// Equivalent condition:
// max character - min character < k
//
// Example:
// s = "abcdf"
// k = 4
// Answer = 4
//
// ============================================================


// ============================================================
// APPROACH 1: BRUTE FORCE
// ============================================================
//
// Idea:
// Try every possible substring [i ... j].
//
// For every substring:
// 1. Maintain minimum character
// 2. Maintain maximum character
// 3. Check max - min < k
// 4. If valid, update maximum length
//
// Time Complexity: O(N^2)
// Space Complexity: O(1)
// ============================================================

int brute(string& s, int k)
{
    int n = s.size();

    int ans = 0;

    // Starting point
    for (int i=0;i<n;i++)
    {
        // Initialize min and max
        char mn=s[i];
        char mx=s[i];
        // Ending point
        for (int j=1;j<n;j++)
        {
            // Add current character

            // Update minimum
            mn=min(mn,s[j]);
        

            // Update maximum
            mx=max(mx,s[j]);

            // Check validity
            // max - min < k
            if(mx-mn<k)
            {
                ans=max(ans,j-i+1);
            }

            // If valid:
            // update ans
        }
    }

    return ans;
}


// ============================================================
// APPROACH 2: OPTIMIZED — SLIDING WINDOW
// ============================================================
//
// Important Observation:
//
// ANY PAIR
//     ↓
// WORST PAIR
//     ↓
// MIN and MAX
//     ↓
// max - min < k
//
// Monotonic Property:
//
// When window expands:
// max - min can only increase or remain same.
//
// Therefore:
// If max - min >= k
//     ↓
// Window is invalid
//     ↓
// Move left pointer i
//
// When valid:
// ans = maximum window length
//
// Time Complexity: O(N) / O(26N) depending on how
// min and max are maintained.
// Space Complexity: depends on data structure.
// ============================================================

int optimal(string& s, int k)
{
    int n = s.size();

    int i = 0;
    int ans = 0;

    multiset<char> st;
   
    for (int j = 0; j < n; j++)
    {
        // Add current character
        st.insert(s[j]);

        // While window is invalid
        while (*st.rbegin()-*st.begin()>=k)
        {
            // Remove s[i]
              st.erase(st.find(s[i]));
              
            // Move i
            i++;
        }

        // Current window valid
        
         ans=max(ans,j-i+1);
        // Update answer
    }

    return ans;
}




// ============================================================
// MAIN
// ============================================================

int main()
{
    string s;
    int k;

    cin >> s >> k;

    // cout << "Brute Force: "
    //      << brute(s, k) << endl;

    cout << "Optimized: "
         << optimal(s, k) << endl;

    return 0;
}