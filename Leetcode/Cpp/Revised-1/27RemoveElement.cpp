
// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

// Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
// Return k.
// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int val = ...; // Value to remove
// int[] expectedNums = [...]; // The expected answer with correct length.
//                             // It is sorted with no values equaling val.

// int k = removeElement(nums, val); // Calls your implementation

// assert k == expectedNums.length;
// sort(nums, 0, k); // Sort the first k elements of nums
// for (int i = 0; i < actualLength; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

 

// Example 1:

// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 2.
// It does not matter what you leave beyond the returned k (hence they are underscores).



class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // int count = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] != val) {
        //         nums[count++] = nums[i];
        //     }
        // }
        // return count;



        // try 1
        // int counter = 0;
        // for( int i=0; i<nums.size(); i++){
        //     if(nums[i] != val){
        //         nums[counter++] = nums[i];
        //     }
        // }
        // return counter;

        // try 2 -> self 
        // basically we need to return the count of val not matching

        // we will creater a var count to keep check of count 
        int count = 0;

        // traverse array to see the vals 
        for(int i=0; i<nums.size(); i++){

            // check if val is equal or not
            if(nums[i] != val){
                
                // update the nums inplace via counter and non duplicate val
                nums[count++] = nums[i];
            }
            else{
                // if same then do not do anything and continue
                continue;
            }
        }
        return count;
    }
};
