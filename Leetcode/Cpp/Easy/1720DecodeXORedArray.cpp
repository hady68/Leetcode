// There is a hidden integer array arr that consists of n non-negative integers.

// It was encoded into another integer array encoded of length n - 1, such that encoded[i] = arr[i] XOR arr[i + 1]. For example, if arr = [1,0,2,1], then encoded = [1,2,3].

// You are given the encoded array. You are also given an integer first, that is the first element of arr, i.e. arr[0].

// Return the original array arr. It can be proved that the answer exists and is unique.

 

// Example 1:

// Input: encoded = [1,2,3], first = 1
// Output: [1,0,2,1]
// Explanation: If arr = [1,0,2,1], then first = 1 and encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
// Example 2:

// Input: encoded = [6,2,7,3], first = 4
// Output: [4,2,0,7,4]
 

// Constraints:

// 2 <= n <= 104
// encoded.length == n - 1
// 0 <= encoded[i] <= 105
// 0 <= first <= 105

// brute force -> time complexity of O(N) and a space complexity of O(N),
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);

        for(int i = 0; i < encoded.size(); i++) {
            if (encoded[i] == ans[i]) {
                ans.push_back(0);
            } else {
                ans.push_back(encoded[i] ^ ans[i]);
            }
        }
        return ans;
    }
};

// optimized -> inplace -> decoding without using extra space
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);

        for(int i = 0; i < encoded.size(); i++) {
            if (encoded[i] == ans[i]) {
                ans.push_back(0);
            } else {
                ans.push_back(encoded[i] ^ ans[i]);
            }
        }
        return ans;
    }
};

//Dry run
// encoded = [6, 2, 7, 3] and first = 4:
// Initial state: encoded = [6, 2, 7, 3], first = 4.
// Insert first at the beginning of encoded:

// encoded = [4, 6, 2, 7, 3].
// encoded[1] = encoded[1] xor encoded[0]
// encoded[1] = 6 xor 4 = 2
// encoded[2] = encoded[2] xor encoded[1]
// encoded[2] = 2 xor 2 = 0
// encoded[3] = encoded[3] xor encoded[2]
// encoded[3] = 7 xor 0 = 7
// encoded[4] = encoded[4] xor encoded[3]
// encoded[4] = 3 xor 7 = 4
// Final state: encoded = [4, 2, 0, 7, 4].
