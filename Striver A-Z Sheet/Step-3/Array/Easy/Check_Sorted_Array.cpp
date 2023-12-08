// Sample Input 1 :
// 4
// 0 0 0 1
// Sample Output 1 :
// 1
// Explanation For Sample Input 1 :
// The given array is sorted in non-decreasing order; hence the answer will be 1. 
// Sample Input 2 :
// 5
// 4 5 4 4 4
// Sample Output 2 :
// 0
// Expected Time Complexity:
// O(n), Where ‘n’ is the size of an input array ‘a’.
// Constraints:
// 1 ≤ 'n' ≤ 5*10^6
// 0 ≤ 'a'[i] ≤ 10^9

// Time limit: 1 sec

// Brute force -> TC -> O(N) SC -> O(1)
int isSorted(int n, vector<int> a) {
    // Iterating over the array 'A'.
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i]) {
            return 0;
        }
    }

    return 1;
}


