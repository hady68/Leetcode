// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.

// Solution

// Brute -> O(n^2) -> using 2 loops
// Calculate product & divide by self) We can simply calculate product of the whole array and for each element in nums, divide the product by nums[i]
// Cases:
// 1. If there are more than one 0s in nums, the result is an array consisting of all 0.
// 2. If there is a single 0 in nums, then the result is an array consisting of all 0 except at the index where there was 0 in nums, which will contain product of rest of array.
// 3. If there's no 0 in nums, then the result is an array ans where ans[i] = prod / nums[i] (prod = product of all elements in nums).
// Time Complexity : O(N)
// Space Complexity : O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1, zeroCnt = count(begin(nums), end(nums), 0);
        if(zeroCnt > 1) return vector<int>(size(nums));               // Case-1
        for(auto c : nums) 
            if(c) prod *= c;                                          // calculate product of all elements except 0
        for(auto& c : nums)
            if(zeroCnt) c = c ? 0 : prod;                             // Case-2
            else c = prod / c;                                        // Case-3
        return nums;
    }
};

//solution 3 Prefix & Suffix Products -This is without '/' operator
// calculating two arrays pre and suf where pre[i] contains product of all nums[j] such that j <= i, and suf[i] contains product of all nums[j] such that j >= i
// ans[i] = pre[i-1] * suf[i+1]
// TC -> O(N)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums), suf(nums), ans(size(nums));
        partial_sum(begin(pre), end(pre), begin(pre), multiplies<int>());       // calculates & stores prefix product at each index
        partial_sum(rbegin(suf), rend(suf), rbegin(suf), multiplies<int>());    // calculates & stores suffix product at each index
        for(int i = 0; i < size(nums); i++)
            ans[i] = (i ? pre[i-1] : 1) * (i+1 < size(nums) ? suf[i+1] : 1);
        return ans;
    }
};

// (Space-Optimized Prefix & Suffix Products in One-Pass)

// The above process can be done in single pass as well. We were first calculating prefix product in one loop and then multiplying it with suffix product in another loop
// // Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(size(nums),1);
        for(int i = 1; i < size(nums); i++)                            // store prefix product
			ans[i] = ans[i-1] * nums[i-1];
        for(int i = size(nums)-1, suffixProd = 1; i >= 0; i--) {
            ans[i] *= suffixProd;                                      // multiply stored prefix product with suffix product
            suffixProd *= nums[i];                                     // update suffix product
        }
        return ans;
    }
};




