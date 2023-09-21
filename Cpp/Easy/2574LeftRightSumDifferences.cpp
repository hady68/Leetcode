// Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:

// answer.length == nums.length.
// answer[i] = |leftSum[i] - rightSum[i]|.
// Where:

// leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
// rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
// Return the array answer.

 

// Example 1:

// Input: nums = [10,4,8,3]
// Output: [15,1,11,22]
// Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
// The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
// Example 2:

// Input: nums = [1]
// Output: [0]
// Explanation: The array leftSum is [0] and the array rightSum is [0].
// The array answer is [|0 - 0|] = [0].
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 105

// Brute force -> using mutiple arrays and loops
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        // array of same length
        vector<int> answer(nums.size());
        vector<int> leftSum(nums.size());
        vector<int> rightSum(nums.size());  
        

        int leftsum = 0;
        int rightsum = 0;
        int size = nums.size()-1;

        // calc the sum for both side

        //loop for left sum
        for(int i = 0; i<=size;i++){
            // condition for 0
            if( i<=0){
                leftSum[i] = leftsum;
                // updating the leftsum for the nexxt elements
                 leftsum += nums[i]; 
            }
            else{
                // for further elements
                leftSum[i] = leftsum;
                leftsum += nums[i];
            }
        }
        //loop for right sum
        for(int i = size; i>=0; i--){
            // condition for last index
            if(i == size){
                rightSum[i] = rightsum;
                // updating the leftsum for the nexxt elements
                 rightsum += nums[i]; 
            }
            else{
                // for further elements
                rightSum[i] = rightsum;
                rightsum += nums[i];
            }
        }
            // dry run -> rightsum [ 15, 11, 3, 0]
            // ans -> answer[i] = rightsum[i] - leftsum[i]
            // calc ans loop    
        for(int i=0; i<=size; i++){
                answer[i] = abs(leftSum[i]-rightSum[i]);
        }  
    return answer;

        }
};


// Optimized code 
