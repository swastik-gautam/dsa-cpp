#include <bits/stdc++.h>
using namespace std;

// Problem: Contains Duplicate

// Description:
// Check if any element appears more than once in the array.

// Approach:
// Use unordered_set to track elements seen so far.
// If element already exists → duplicate found.

// Time Complexity: O(n)
// Space Complexity: O(n)

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> st;

    for (int x : nums) {
        if (st.count(x)) {
            return true;
        }
        st.insert(x);
    }

    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1};

    if (containsDuplicate(nums))
        cout << "true\n";
    else
        cout << "false\n";
}
