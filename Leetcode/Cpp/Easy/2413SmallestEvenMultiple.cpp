// Given a positive integer n, return the smallest positive integer that is a multiple of both 2 and n.
 

// Example 1:

// Input: n = 5
// Output: 10
// Explanation: The smallest multiple of both 5 and 2 is 10.
// Example 2:

// Input: n = 6
// Output: 6
// Explanation: The smallest multiple of both 6 and 2 is 6. Note that a number is a multiple of itself.
 

// Constraints:

// 1 <= n <= 150

//brute 
class Solution {
public:
    int smallestEvenMultiple(int n) 
    {
        if(n%2==0) return n;                // if n is multiple of 2 it means it will also the multiple of n so return n
        return n*2;                         // if it is not multiple of 2 then multiply it with 2 and return so it will become multiple of 2 as well
    }
};
