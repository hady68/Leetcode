// Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
// Return the array in the form [x1,y1,x2,y2,...,xn,yn].

// Example 1:
// Input: nums = [2,5,1,3,4,7], n = 3
// Output: [2,3,5,4,1,7] 
// Explanation: Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7].

// Example 2:
// Input: nums = [1,2,3,4,4,3,2,1], n = 4
// Output: [1,4,2,3,3,2,4,1]

// Example 3:
// Input: nums = [1,1,2,2], n = 2
// Output: [1,2,1,2]
 

// Constraints:
// 1 <= n <= 500
// nums.length == 2n
// 1 <= nums[i] <= 10^3


// Using Time -> O(n) and space O(N) -> with 2 pointers and an extra array
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> ans(2 * n); // Use 2 * n instead of 2n
        int first = 0;
        int second = n; // No need to add 1 here

        for(int i = 0; i < n; i++){
            ans[i * 2] = nums[first]; // Use i * 2 to access even indices
            ans[i * 2 + 1] = nums[second]; // Use i * 2 + 1 to access odd indices

            first++;
            second++;
        }

        return ans;
    }
};


// Better -> Time -> O(N) SC -> O(1) -> using inplace -> using the formula ->
//Suppose we have 2 numbers num1 = 4 and num2 = 9 and maxValue = 10
//Formula:
//to store -> pair = (num2 × maxValue) + num1
//to retrieve -> pair % maxValue and pair / maxValue
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        int len = nums.size();
        
		// to store the pair of numbers in right half of the original array
        for(int i = n; i < nums.size(); i++) {
            nums[i] = (nums[i] * 1024) + nums[i - n];
        }
        
        int index = 0;
		// to retrive values from the pair of numbers and placing those retrieved value at their desired position
        for(int i = n; i < nums.size(); i++, index += 2) {
            nums[index] = nums[i] % 1024;
            nums[index + 1] = nums[i] / 1024;
        }
        
        return nums;
        
    }
};
