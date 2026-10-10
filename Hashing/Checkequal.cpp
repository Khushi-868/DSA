#include <bits/stdc++.h>
using namespace std;

bool solve(int k) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> freq;
    for(int i = 0; i < n; i++) {
        if(freq.find(arr[i]) != freq.end() && i - freq[arr[i]] <= k) {
            return true;

        }
        freq[arr[i]] = i;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k;
    cin>>k;

    if(solve(k)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}