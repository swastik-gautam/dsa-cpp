#include<bits/stdc++.h>
using namespace std;

// Problem: 3Sum Closest 

// Discription:
// Given an integer array nums and an integer target
// - return the sum of three integers in nums such that.
// - the sum is closest to target.

// Approach: Sorting + Two Pointers
// Fix one element, then use two pointers to find closest sum.
// Track best sum based on minimum difference from target.

// Time Complexity: O(n^2)
// Space Complexity: O(1)

int threeSumClosest(vector<int>& nums, int target) {
  sort(nums.begin(),nums.end());
  int n = nums.size();
  int best = nums[0]+nums[1]+nums[2];
    for(int i = 0; i < n-2; i++){
      int l = i + 1;
      int r = n - 1;

        while(l<r){
          int temp = nums[i]+nums[r]+nums[l];
            if(abs(temp-target) < abs(best-target)){
              best = temp;
              }
              if(temp == target){
                return temp;
              }
              else if(temp<target){
                l++;
              }
              else{
                r--;
              }
            }
        }

        return best;
    }

int main() {

  vector<int> nums = {-1,2,1,-4};
  int target = 1;

  int resutl =  threeSumClosest(nums,target);

  cout << resutl << "\n";
  
  return 0;
}

