#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const ll MOD = 1000000007;
long long dp[2001][5001];

int digitSum(int x) {
    int sum = 0;

    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }

    return sum;
}

int main() {

    int n;
    cin >> n;

    vector<int> required_sums(n);

    for (int i = 0; i < n; i++) {
        cin >> required_sums[i];
    }

    // Base case
    dp[0][0] = 1;

    for (ll i = 1; i <= n; i++) {

        ll prefix = 0;

        for (ll j = 0; j <= 5000; j++) {

            // Prefix sum of previous row
            prefix = (prefix + dp[i - 1][j]) % MOD;

            if (j >= 1 && digitSum(j) == required_sums[i - 1]) {
                dp[i][j] = prefix;
            }
            else {
                dp[i][j] = 0;
            }
        }
    }

    ll ans = 0;

    for (ll j = 0; j <= 5000; j++) {
        ans = (ans + dp[n][j]) % MOD;
    }

    cout << ans;

    return 0;
}