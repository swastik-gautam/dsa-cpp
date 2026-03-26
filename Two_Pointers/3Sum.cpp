#include<bits/stdc++.h>
using namespace std; 

// Problem: 3Sum (LeetCode 15)

// Description:
// Given an integer array nums, return all unique triplets [a, b, c]
// such that a + b + c = 0.
// The solution must not contain duplicate triplets.

// Approach:
// Sorting + Two Pointers
// - First, sort the array
// - Fix one element (i) and use two pointers (left, right)
// - Move pointers based on sum:
//     sum < 0 → move left forward
//     sum > 0 → move right backward
//     sum == 0 → store triplet and skip duplicates
// - Skip duplicate elements for i, left, and right

// Time Complexity: O(n^2)
// Space Complexity: O(1) (excluding result)

// Pattern: Two Pointers + Sorting

// Important:
// - Avoid duplicates carefully
// - Sorting is required for two pointer technique

vector<vector<int>> threeSum(vector<int>& nums){
    int n = nums.size();
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n-2; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int l = i + 1;
        int r = n - 1;

        while(l < r){
            int sum = nums[i] + nums[l] + nums[r];

            if(sum == 0){
                ans.push_back({nums[i], nums[l], nums[r]});

                while(l < r && nums[l] == nums[l+1]) l++;
                while(l < r && nums[r] == nums[r-1]) r--;

                l++;
                r--;
            }
            else if(sum < 0){
                l++;
            }
            else{
                r--;
            }
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = threeSum(nums);

    for (auto &triplet : result) {
        cout << "[ ";
        for (int x : triplet) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}