// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Example 2:
// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

// Example 3:
// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 
// Constraints:
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
 
// Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

// Brue -> try all subarrays using 2 loops , calculate the max using another loop inside
// TC- O(n^3) SC-> O(1)

// Better -> use 2 loop to calculate the sum -> sum =0 in first loop and in the nested loop -> add the next element in sum and check maximum
// Tc- O(n^2) 

// Best -> using kadane's algorithm -> not carrying negative sum forward -> if sum is +ve can carry -ve element -> using 1 loop only
// compare sum with maximum and return the maximum
class Solution {
public:
    int maxSubArray(vector<int>& nums) { 
        if(nums.size() == 1){
            return nums[0];
        }
        int sum = 0;
        int maxi = nums[0];
        for(int i=0; i<nums.size();i++){
            sum += nums[i];
            if(sum>maxi){
                maxi = sum;
            }
            // negative sum will not go forward
            if(sum < 0 ){
                sum = 0;     
        } 
        return maxi;
    }
};
