// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

 

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
 

// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105
 

// Follow up:

// Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
// Could you do it in-place with O(1) extra space?


// using reverse 3 times
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        // rotate all ex -> 1 2 3 4 5 6 7 k =3 
        reverse(nums.begin(), nums.end()); // 7 6 5 4 3 2 1 
       // reverse the last k elements 
        reverse(nums.begin(), nums.begin()+k); // 7 6 5 1 2 3 4  
        // reverse first k elements 
        reverse(nums.begin()+k, nums.end()); // 5 6 7 1 2 3 4 

    }
}


// Rotating by 1 k times
class Solution {
public:
	void rotateByOne(vector<int> &nums){
		int n = nums.size(), temp = nums[n-1];
		for(int i=n-1; i>0; i--){
			nums[i] = nums[i-1];
		}
			nums[0] = temp;
	}
    void rotate(vector<int>& nums, int k) {
        for(int i=0; i<k; i++) rotateByOne(nums);
    }
};


// Using the formula (i+k%n)  - with extra space

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        
        vector<int> temp(nums.size());
        for(int i=0; i<nums.size();i++){

        temp[(i+k)%nums.size()] = nums[i];

        }

        nums = temp;
    }
};
