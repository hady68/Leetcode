// Problem Statement



// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 7
// Sample Output 1 :
// 1 2 6
// Explanation Of Sample Input 1:
// Input: ‘n’ = 7

// Output: 1 2 6

// Explanation: Factorial numbers less than or equal to ‘7’ are ‘1’, ‘2’, and ‘6’.
// Sample Input 2:
// 2
// Sample Output 2:
// 1 2
// Explanation Of Sample Input 2:
// Input: ‘n’ = 2

// Output: 1 2

// Explanation: Factorial numbers less than or equal to ‘2’ are ‘1’ and ‘2’.
// Expected Time Complexity:
// The expected time complexity is O(m), where ‘m’ is the number of factorial numbers which are less than or equal to ‘n’.
// Expected Space Complexity:
// The expected space complexity is O(m), where ‘m’ is the number of factorial numbers which are less than or equal to ‘n’.
// Constraints:
// 1 <= n <= 10^18

// Time Limit: 1-sec


// using loop
vector<long long> factorialNumbers(long long n) {
    // Write Your Code Here

    vector<long long> res;
    long long ans = 1;

    for(int i=1; ans*i<=n; i++){
        ans = ans * i;
        res.push_back(ans);
    }

    return res;

}

// recursion

long long fact(long long j){
    if(j<=1)    return 1;
    else
        return j*fact(j-1);
}

void factorial(long long i,long long n, vector<long long >& ans){
    if(fact(i)<=n){
        ans.push_back(fact(i));
        factorial(i+1,n,ans);
    }
    else return ;
}

vector<long long> factorialNumbers(long long n) {
    long long i=1;
    vector<long long> ans;
    factorial(i,n,ans);
    return ans;

}
