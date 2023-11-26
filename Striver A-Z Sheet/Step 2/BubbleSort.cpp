// Approach:

// The algorithm steps are as follows:
// 1. Run 2 loops ( outer loop as range from n-1 to 0) inner loop ( for comparing)
// 2. compare the adjacent elements if arr[j]>arr[j+1] -> swap
// 3. after each iteration largest element will get sorted 

// TC -> Time complexity: O(N2), (where N = size of the array), for the worst, and average cases.
// Reason: If we carefully observe, we can notice that the outer loop, say i,
//   is running from n-1 to 0 i.e. n times, and for each i, the inner loop j runs from 0 to i-1. 
//   For, i = n-1, the inner loop runs n-1 times, for i = n-2, the inner loop runs n-2 times, and so on.
//   So, the total steps will be approximately the following: (n-1) + (n-2) + (n-3) + ……..+ 3 + 2 + 1. 
//   The summation is approximately the sum of the first n natural numbers i.e. (n*(n+1))/2. 
//   The precise time complexity will be O(n2/2 + n/2). Previously, 
//   we have learned that we can ignore the lower values as well as the constant coefficients.
//   So, the time complexity is O(n2). Here the value of n is N i.e. the size of the array.

// Space Complexity: O(1)

// Optimized approach (Reducing time complexity for the best case):
// The best case occurs if the given array is already sorted. We can reduce the time complexity to O(N) by just adding a small check inside the loops.
// We will check in the first iteration if any swap is taking place. If the array is already sorted no swap will occur and we will break out from the loops. 
// Thus the iteration of the outer loop will be just 1. And our overall time complexity will be O(N).


void bubble_sort(int arr[], int n) {
    // bubble sort
    for (int i = n - 1; i >= 0; i--) {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0) {
            break;
        }
    }
