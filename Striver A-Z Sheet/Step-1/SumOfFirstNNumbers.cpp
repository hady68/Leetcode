// Problem Statement
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 3
// Sample Output 1 :
// 6
// Explanation Of Sample Input 1:
// Input: ‘n’ = 3

// Output: 6

// Explanation: The sum of the first 3 natural numbers is 1 + 2 + 3, equal to 6.
// Sample Input 2:
// 5
// Sample Output 2:
// 15
// Explanation Of Sample Output 2:
// Input: ‘n’ = 5

// Output: 15

// Explanation: The sum of the first 5 natural numbers is 1 + 2 + 3 + 4 + 5, equal to 15.
// Expected Time Complexity:
// The expected time complexity is O(1).
// Expected Space Complexity:
// The expected space complexity is O(1).
// Constraints:
// 1 <= n <= 10^9
// Time Limit: 1 sec


// Recursion -> TLE

void add(long long& ans,long long n){
   if(n==0){
       return;
   }
   ans += n;
   add(ans,n-1);
}
long long sumFirstN(long long n) {
// Write your code here.
long long ans = 0;
add(ans,n);
return ans;
    

}
// Better 
return (n * (n + 1)) / 2;
