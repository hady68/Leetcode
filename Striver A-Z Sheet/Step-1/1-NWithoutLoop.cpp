// Problem Statement

// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 5
// Sample Output 1 :
// 1 2 3 4 5
// Explanation Of Sample Input 1:
// The array contains all integers from 1 to 5 in ascending order.
// Sample Input 2:
// 2
// Sample Output 2:
// 1 2
// Explanation Of Sample Input 2:
// The array contains all integers from 1 to 2 in ascending order.
// Expected Time Complexity:
// The expected time complexity is O(n), where 'n' is the given integer.
// Constraints:
// 1 <= n <= 10^6

// Time Limit: 1-sec
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 5
// Sample Output 1 :
// 1 2 3 4 5
// Explanation Of Sample Input 1:
// The array contains all integers from 1 to 5 in ascending order.
// Sample Input 2:
// 2
// Sample Output 2:
// 1 2
// Explanation Of Sample Input 2:
// The array contains all integers from 1 to 2 in ascending order.
// Expected Time Complexity:
// The expected time complexity is O(n), where 'n' is the given integer.
// Constraints:
// 1 <= n <= 10^6

// Time Limit: 1-sec


void results(int i,vector<int>& result, int n) {
    result.push_back(i);
    if (i == n) {
        return;
    }
    results(i + 1, result, n);
}

vector<int> printNos(int x) {
  vector<int> prints;
    results(1, prints, x);
    return prints;

}
