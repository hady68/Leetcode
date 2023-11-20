// Problem Statement

// Sample Input 1:
// 6 4
// 1 3 4 3 4 1
// Sample Output 1:
// 2 0 2 2 0 0
// Explanation Of Sample Input 1 :
// Frequency table:
// Number         Count 
//  1                2
//  2                0
//  3                2
//  4                2
//  5                0
//  6                0
// Sample Input 2 :
// 5 5
// 1 2 3 4 5
// Sample Output 2 :
// 1 1 1 1 1
// Explanation Of Sample Input 2 :
// Frequency table:
// Number         Count 
//  1                1
//  2                1
//  3                1
//  4                1
//  5                1
// Constraints:
// 1  <= n <= 10^5
// 1  <= x <= 10^5
// 1 <= arr[i] <= x


#include <bits/stdc++.h>
vector<int> countFrequency(int n, int x, vector<int> &nums) {
  // Write your code here.
 vector<int> ans(n);
    for(int i=0;i<nums.size();i++){
        ans[nums[i]-1]++;
    }
    return ans;

}
