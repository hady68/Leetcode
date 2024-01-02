// Problem Statement: You are given an array of integers, your task is to move all the zeros in the array to the end of the array and move non-negative integers to the front by maintaining their order.

// Examples
// Example 1:
// Input: 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1
// Output: 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0
// Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order

// Example 2:
// Input: 1,2,0,1,0,4,0
// Output: 1,2,1,4,0,0,0
// Explanation: All the zeros are moved to the end and non-negative integers are moved to front by maintaining order



// Brute force -> move non zero to a temp array first then rest 0 to the temp array -> using an extra space for this new arr
// TC -> O(N) + O(X) + O(N-X) ~ O(2*N), where N = total no. of elements,
// SC => O(N)

vector<int> moveZeros(int n, vector<int> a) {
    //temporary array:
    vector<int> temp;
    //copy non-zero elements
    //from original -> temp array:
    for (int i = 0; i < n; i++) {
        if (a[i] != 0)
            temp.push_back(a[i]);
    }

    // number of non-zero elements.
    int nz = temp.size();

    //copy elements from temp
    //fill first nz fields of
    //original array:
    for (int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }

    //fill rest of the cells with 0:
    for (int i = nz; i < n; i++) {
        a[i] = 0;
    }
    return a;
}

// OPTIMAL APP -> Using Two Pointers 
// TC -> O(n) SC -> O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int j = -1;
    int n = nums.size();
    //place the pointer j:
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            j = i;
            break;
        }
    }

    //no non-zero elements:
    if (j == -1) return;

    //Move the pointers i and j
    //and swap accordingly:
    for (int i = j + 1; i < n; i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}
    
};

