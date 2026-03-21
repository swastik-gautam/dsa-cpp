#include <bits/stdc++.h>
using namespace std;

// Problem: Two Sum

// Description:
// Given an array of integers and a target, return indices of two numbers
// such that they add up to the target.

// Approach:
// Use unordered_map to store visited elements.
// For each element, check if (target - current) already exists.
// If yes → solution found.

// Time Complexity: O(n)
// Space Complexity: O(n)

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];

        if (mp.count(need)) {
            return {mp[need], i};
        }

        mp[nums[i]] = i;
    }

    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);

    cout << ans[0] << " " << ans[1] << endl;
}
