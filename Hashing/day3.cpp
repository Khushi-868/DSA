//-> Given an array “nums” of size “N” - find the total number of pairs(i,j) [i<j] such that abs(nums[i] - nums[j]) = target where target>=0 (Note :- target always should be >=0 in this question because abs(something) is always >=0)
// it is abs we need to check both cases 
//  we have to handle for zero also 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>

using namespace std;

// Shorthands & Type Aliases
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

// Common Constants
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

// Function to solve a single testcase
void solve() {
    int n;
    if (!(cin >> n)) return; // Read input size; handles EOF safely
    int target;
    cin>>target;
    
    std::vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // --- YOUR LOGIC GOES HERE ---
    unordered_map<ll ,int>mp;
    int counter=0;
    for(int j=0;j<n;j++)
    {
        if(target>0)
        {
           int dl1= a[j] +target;
           int dl2=a[j] -target;
           if(mp.find(dl1)!=mp.end())
           {
              counter+=mp[dl1];
           }
            if(mp.find(dl2)!=mp.end())
           {
              counter+=mp[dl2];
           }

        }else{
            if(mp.find(a[j])!= mp.end())
            {
                counter+=mp[a[j]];
            }

        }
        mp[a[j]]+=1;
    }
    cout<<counter;
    
}

int main() {
    // 1. FAST I/O: Crucial to prevent Time Limit Exceeded (TLE) in C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 2. Handling Test Cases:
    // Some questions have 'T' testcases, some have only 1.
    // Case A: If input starts with number of testcases T:
    /*
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    */
    
    // Case B: Single testcase per run (most common in Infosys):
    solve();
    
    return 0;
}