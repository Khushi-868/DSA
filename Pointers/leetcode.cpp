#include <bits/stdc++.h>
using namespace std;

string shortestBeautifulSubstring(string s, int k) {

    int left = 0;
    int n = s.size();
    int ones = 0;
    string ans = "";

    for (int right = 0; right < n; right++) {

        // Add current character
        if (s[right] == '1') {
            ones++;
        }

        // Too many ones -> shrink window
        while (ones > k) {

            if (s[left] == '1') {
                ones--;
            }

            left++;
        }

        // Remove unnecessary leading zeros
        while (ones == k && s[left] == '0') {
            left++;
        }

        // Current window has exactly k ones
        if (ones == k) {

            string curr = s.substr(left, right - left + 1);

            // Shorter substring
            if (ans == "" || curr.length() < ans.length()) {
                ans = curr;
            }

            // Same length -> lexicographically smaller
            else if (curr.length() == ans.length() && curr < ans) {
                ans = curr;
            }
        }
    }

    return ans;
}

int main() {

    string s;
    int k;

    cout << "Enter binary string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    string result = shortestBeautifulSubstring(s, k);

    cout << "Answer: " << result << endl;

    return 0;
}