#include <bits/stdc++.h>
using namespace std;

// Find total number of pairs (i,j), i < j,
// such that abs(nums[i] - nums[j]) = target

int main()
{
    int n;
    int target;
    int res = 0;

    cin >> n >> target;

    vector<int> ar;

    for (int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        ar.push_back(y);
    }

    unordered_map<int, int> mp;

    for (int j = 0; j < n; j++)
    {
        int def_1 = ar[j] + target;
        int def_2 = ar[j] - target;

        if (mp.count(def_1))
            res += mp[def_1];

        if (mp.count(def_2))
            res += mp[def_2];

        mp[ar[j]]++;
    }

    cout << res << endl;

    return 0;
}