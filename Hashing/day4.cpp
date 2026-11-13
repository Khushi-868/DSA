// -> Given an array “nums” of size “N” - find the total number of pairs(i,j) [i<j] such that (nums[i] + nums[j])%5 = 0 (nums[i]>=0 for all i) 

// Input :- [2,2,5,5,3,3] 
// Output :- 5


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
    
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    //unordered_map<ll,int> mp; we will replace with frequency
    vector<ll> freq(5,0);
    ll ans=0;
    
    // --- YOUR LOGIC GOES HERE ---
    for(int j=0;j<n;j++)
    {
        int real=nums[j]%5;
        int r=5-real;
        //if r=5 then 
        r=r%5;
        ans+=freq[r];
        freq[nums[j]%5]++;

    }
        cout << ans << "\n";
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