#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Subarray

// Description:
// Find the contiguous subarray with the largest sum.

// Approach:
// Use Kadane's Algorithm.
// At each step, decide whether to extend current subarray or start new.
// Keep track of maximum sum seen so far.

// Time Complexity: O(n)
// Space Complexity: O(1)

int maxSubArray(vector<int>& nums) {
    int current = nums[0];
    int best = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        current = max(nums[i], current + nums[i]);
        best = max(best, current);
    }

    return best;
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubArray(nums) << endl;
}
