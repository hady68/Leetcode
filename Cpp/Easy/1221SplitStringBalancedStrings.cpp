// Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

// Given a balanced string s, split it into some number of substrings such that:

// Each substring is balanced.
// Return the maximum number of balanced strings you can obtain.

 

// Example 1:

// Input: s = "RLRRLLRLRL"
// Output: 4
// Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
// Example 2:

// Input: s = "RLRRRLLRLL"
// Output: 2
// Explanation: s can be split into "RL", "RRRLLRLL", each substring contains same number of 'L' and 'R'.
// Note that s cannot be split into "RL", "RR", "RL", "LR", "LL", because the 2nd and 5th substrings are not balanced.
// Example 3:

// Input: s = "LLLLRRRR"
// Output: 1
// Explanation: s can be split into "LLLLRRRR".
 

// Constraints:

// 2 <= s.length <= 1000
// s[i] is either 'L' or 'R'.
// s is a balanced string.

// Brute force -> using 2 loops -> Tc -> O(n)^2 
class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            int balance = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == 'R') {
                    balance++;
                } else if (s[j] == 'L') {
                    balance--;
                }

                if (balance == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};


// better approach -> using a stack -> Tc-> O(N) && SC -> O(N)

class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        std::stack<char> store;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (store.empty() || store.top() == c) {
                store.push(c);
            } else {
                store.pop();
                if (store.empty()) {
                    count++;
                }
            }
        }

        return count;
    }
};


// Best approach -> using a balance variable and 1 loop _> TC _> O(N) and SC -> O(1)
class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int balance = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == 'R') {
                balance++;
            } else if (c == 'L') {
                balance--;
            }

            if (balance == 0) {
                count++;
            }
        }

        return count;
    }
};
