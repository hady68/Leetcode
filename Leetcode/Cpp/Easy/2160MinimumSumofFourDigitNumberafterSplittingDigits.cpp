// You are given a positive integer num consisting of exactly four digits. Split num into two new integers new1 and new2 by using the digits found in num. Leading zeros are allowed in new1 and new2, and all the digits found in num must be used.

// For example, given num = 2932, you have the following digits: two 2's, one 9 and one 3. Some of the possible pairs [new1, new2] are [22, 93], [23, 92], [223, 9] and [2, 329].
// Return the minimum possible sum of new1 and new2.

 

// Example 1:

// Input: num = 2932
// Output: 52
// Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
// The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.
// Example 2:

// Input: num = 4009
// Output: 13
// Explanation: Some possible pairs [new1, new2] are [0, 49], [490, 0], etc. 
// The minimum sum can be obtained by the pair [4, 9]: 4 + 9 = 13.
 

// Constraints:

// 1000 <= num <= 9999

// brute force -> Tc-> O(K * log(K)), where K is the number of digits in n. -> seperate the digits into a vecotr -> sort it -> even digits together and odd digits together to form a min number 
// ex -> 2 2 3 9 -> min 2 3 and 2 9 

class Solution {
public:
    int minimumSum(int num) {
        // get individual digits in a vector 
        // sort it -> as min is required
        vector<int>digits;
        while(num>0){
            int dig = num%10; //getting digit
            digits.push_back(dig);
            num /= 10;
        }
        sort(digits.begin(), digits.end()); // sort the values
        // even and odd positions will be updated as
        int num1=0, num2=0;
        for(int i=0; i<digits.size();i++){
            // if index is even 
            if(i%2==0)
                num1 = num1*10 + digits[i];
            // odd index
            else
                num2 = num2*10 + digits[i];
        }
        return (num1 + num2);
    }
};

// cleaner code
// Time: O(1) or more specifically, O(KlogK), where `K` is the number of digits in `n`
// Space: O(1) or O(K)
class Solution {
public:
    int minimumSum(int n) {
        int d[4] = {};
        for (int i = 0; i < 4; ++i, n /= 10) d[i] = n % 10;
        sort(begin(d), end(d));
        return 10 * (d[0] + d[1]) + d[2] + d[3];
    }
};
