// Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.
// A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

// Example 1:
// Input: nums = [0,2,1,5,3,4]
// Output: [0,1,2,4,5,3]
// Explanation: The array ans is built as follows: 
// ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
//     = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
//     = [0,1,2,4,5,3]

// Example 2:
// Input: nums = [5,0,1,2,3,4]
// Output: [4,5,0,1,2,3]
// Explanation: The array ans is built as follows:
// ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
//     = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
//     = [4,5,0,1,2,3]

// brute for -> make ans vector -> pushback values in it with a loop -> O(N) space -> o(N)
//By using ans.reserve(n), you're telling the vector to allocate memory for n elements upfront, which reduces the number of reallocations and can improve the performance, 
//especially when dealing with large vectors. This can lead to better memory management and overall execution speed.
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;
        ans.reserve(n); // Reserve space for n elements -> for better performance 

        for(int i = 0; i<n;i++){
            ans.push_back(nums[nums[i]]);
        }

        return ans;
        
    }
};


// better -> O(1) -> using mathematical formula SC -> O(1)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0; i<n; i++){
         
        // let a=3 b=4 n=6
        // a = a + (b%n)*n -> 3 + (4%6)*6-> 3+ 24 -> 27
        // a= a%n -> 27%6 -> 3
        // b = a/n -> 27/6 -> 4
            
            nums[i] = nums[i] + n*(nums[nums[i]] % n);
        }
        
        for(int i=0; i<n; i++){
            nums[i] = nums[i]/n;
        }
        
        return nums;
        
    }
}; 

// better -> 
