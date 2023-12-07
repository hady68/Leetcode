// Problem statement
// Sample input 1:
// 6
// 4 7 8 6 7 6 
// Sample output 1:
// 8
// Explanation of sample input 1:
// The answer is 8.
// From {4 7 8 6 7 6}, 8 is the largest element.
// Sample input 2:
// 8
// 5 9 3 4 8 4 3 10 
// Sample output 2:
// 10
// Expected Time Complexity:
// O(n), Where ‘n’ is the size of an input array ‘arr’.
// Constraints :
// 1 <= 'n' <= 10^5
// 1 <= 'arr[i]' <= 10^9

// Time Limit: 1 sec


#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {

    int largest = INT_MIN;
    for( int i=0; i<n; i++) {

      if (arr[i] > largest) {
          largest = arr[i];
      }
    }
    return largest;    
}
