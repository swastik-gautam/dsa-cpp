#include<bits/stdc++.h>
using namespace std;

// Problem: Candy (LeetCode 135)

// Description:
// Given ratings of children, distribute candies such that:
// 1. Each child gets at least 1 candy
// 2. Higher rated child gets more candies than neighbors

// Approach:
// Greedy (Bidirectional - Left & Right pass)
// - Traverse left → right to handle left neighbor
// - Traverse right → left to handle right neighbor
// - Take max from both to satisfy both conditions

// Time Complexity: O(n)
// Space Complexity: O(n)

int candy(vector<int>& ratings){
  int n = ratings.size();
  vector<int>left(n,1),right(n,1);

  for(int i = 1; i < n; i++){
    if(ratings[i]>ratings[i-1]){
      left[i] = left[i-1] + 1;
    }
  }

  for(int i = n-2; i >= 0; i--){
    if(ratings[i]>ratings[i+1]){
      right[i] = right[i+1] + 1;
    }
  }

  int ans = 0;

  for(int i = 0; i < n; i++){
    ans += max(right[i] , left[i]);
  }

  return ans;

}

int main() {

  vector<int> ratings = {1,0,2};

  int result = candy(ratings);
  cout << resutl << "\n";

  return 0;
}












