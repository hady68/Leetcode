// Problem Statement


// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// 8
// 3 1 1 7 4 2 6 11
// Sample Output 1:
// 11 6 2 4 7 1 1 3    
// Explanation Of Sample Input 1 :
// After reversing the array, it looks like this [11, 6, 2, 4, 7, 1, 1, 3].
// Sample Input 2:
// 4
// 8 1 3 2
// Sample Output 2:
// 2 3 1 8
// Explanation Of Sample Input 2 :
// After reversing the array, it looks like this [2, 3, 1, 8].
// Expected Time Complexity
// The expected time complexity is O(n).
// Constraints:
// 1 <= 'n' <= 10^6
// -10^9 <= 'arr[i]' <=10^9

void reversed(int n, vector<int>& nums, int a){

    if(a>=n/2)
    return;

    swap(nums[a], nums[n-1-a]);
    reversed(n,nums, a+1);
}


vector<int> reverseArray(int n, vector<int> &nums)
{
    // Write your code here.

    //brute -> read arr from back
    // use reverse function from vectors
    // swap using 2 pointers
    // swap via recursion

    int a = 0;
    reversed(n,nums,a);
    return nums; 

}
