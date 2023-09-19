// You are given a 0-indexed integer array nums and an integer k.

// Return an integer that denotes the sum of elements in nums whose corresponding indices have exactly k set bits in their binary representation.

// The set bits in an integer are the 1's present when it is written in binary.

// For example, the binary representation of 21 is 10101, which has 3 set bits.
 

// Example 1:

// Input: nums = [5,10,1,5,2], k = 1
// Output: 13
// Explanation: The binary representation of the indices are: 
// 0 = 0002
// 1 = 0012
// 2 = 0102
// 3 = 0112
// 4 = 1002 
// Indices 1, 2, and 4 have k = 1 set bits in their binary representation.
// Hence, the answer is nums[1] + nums[2] + nums[4] = 13.
// Example 2:

// Input: nums = [4,3,2,1], k = 2
// Output: 1
// Explanation: The binary representation of the indices are:
// 0 = 002
// 1 = 012
// 2 = 102
// 3 = 112
// Only index 3 has k = 2 set bits in its binary representation.
// Hence, the answer is nums[3] = 1.
 

// Constraints:

// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 105
// 0 <= k <= 10


// using 2 loops -> TC -> O(N*log(N)

class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0; // Variable to store the sum

        for (int i = 0; i < nums.size(); i++) {
            int count = countSetBits(i); // Count set bits in the binary representation of i
            if (count == k) {
                sum += nums[i];
            }
        }

        return sum;
    }

    int countSetBits(int n) {
        int count = 0;
        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};

// Using built in STL funtion -> Tc -> O(N)
class Solution {
public:
    // Function to calculate the sum of elements at indices with 'k' set bits in their binary representation
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0; // Initialize the answer variable to 0

        // Iterate through the indices of the 'nums' vector
        for (int i = 0; i < nums.size(); i++) {
            // Check if the number of set bits in the binary representation of 'i' is equal to 'k'
            if (__builtin_popcount(i) == k) {
                ans += nums[i]; // If 'k' set bits are found, add the corresponding 'nums' element to the answer
            }
        }

        return ans; // Return the final sum
    }
};
