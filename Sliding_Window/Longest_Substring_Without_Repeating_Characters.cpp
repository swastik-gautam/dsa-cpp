#include<bits/stdc++.h>
using namespace std;

// Problem: Longest Substring Without Repeating Characters

// Description:
// Given a string s, find the length of the longest substring
// without repeating characters.

// Approach:
// Sliding Window
// - Use two pointers (left, right)
// - Expand right pointer
// - If duplicate appears, shrink from left
// - Maintain a map to track character frequency

// Time Complexity: O(n)
// Space Complexity: O(n)

// Pattern: Sliding Window

int lengthOfLongestSubstring(string s) {
    int best = 0;
    int left = 0;

    map<char,int> mp;

    for(int i = 0; i < s.size(); i++){
        mp[s[i]]++;

        // shrink window if duplicate
        while(mp[s[i]] > 1){
            mp[s[left]]--;
            left++;
        }

        best = max(best, i - left + 1);
    }

    return best;
}

int main() {
    string s = "ababaja";

    int ans = lengthOfLongestSubstring(s);

    cout << ans << "\n";

    return 0;
}
