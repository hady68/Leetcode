// Problem statement
// Sample Input 1 :
// 4
// 3 4 5 2
// Sample Output 1 :
// 4 3
// Explanation For Sample Input 1 :
// The second largest element after 5 is 4 only, and the second smallest element after 2 is 3.
// Sample Input 2 :
// 5
// 4 5 3 6 7
// Sample Output 2 :
// 6 4
// Expected Time Complexity:
// O(n), Where ‘n’ is the size of an input array ‘a’.
// Constraints:
// 2 ≤ 'n' ≤ 10^5
// 0 ≤ 'a'[i] ≤ 10^9

// Time limit: 1 sec

// Brute force -> using sort function -> TC -> O(nlogn)
vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Brute force -> sort and return 2nd and n-2 element 
        vector<int> ans;
        sort(a.begin(), a.end());
        ans.push_back(a[n-2]);
        ans.push_back(a[1]);
        return ans;        
}

// Better TC-> O(N) SC-> O(1)

vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Initializing the driver variables.
    int small = INT_MAX, secondSmall = INT_MAX;
    int large = INT_MIN, secondLarge = INT_MIN;

    // Iterating over an array and calculating the smaller and larger numbers.
    for (int i = 0; i < n; i++) {
        small = min(small, a[i]);
        large = max(large, a[i]);
    }

    // Iterating again and updating the second order numbers.
    for (int i = 0; i < n; i++) {
        if (a[i] < secondSmall && a[i] != small) {
            secondSmall = a[i];
        }
        if (a[i] > secondLarge && a[i] != large) {
            secondLarge = a[i];
        }
    }

    return {secondLarge, secondSmall};
}
