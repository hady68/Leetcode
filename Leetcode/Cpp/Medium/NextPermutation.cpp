
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100



// Brute ->
// generate all possible permutations using recursion
// use linear search to find the element 
// print the next element if it's not the last element, otherwise priint the first if it is the last element 
// Tc -> O(N!*N) -> Huge optimize it 

// Better -> use STL next_permutations() library
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

     next_permutation(nums.begin(), nums.end());

    }
};

// Optimal -> implement the stl lib in code
// find out the first break point from the end (a[i]<a[i+1])
// Find the first term greater than that break point and swap them 
// sort the rest of the array such that it reduces in value (ascending order)
// if ans is not found just rev the arr and return edge case)
// for sort ( you can also just reverse the array)

// Tc- O(3N)
// SC- O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

     int ind = -1;
     int n = nums.size();

     for(int i = n-2; i>=0; i--){
         // first break point 
         if(nums[i]<nums[i+1]){
            // store that ind 
            ind = i;
            break;

         }
     }

    //  if(ind == -1){
    //      reverse(nums.begin(),nums.end());
    //  }

     // loop till ind and find the first greatest elem

     for(int i=n-1; i>=ind && ind !=-1; i--){
         if(nums[i]>nums[ind]){
         swap(nums[i],nums[ind]);
         break;

         }
     }

     reverse(nums.begin() + ind + 1, nums.end());

    }
};
