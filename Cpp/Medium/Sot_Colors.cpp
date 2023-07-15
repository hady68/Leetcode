// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.


//Brute force -> Use Sort function -> time complexity -> O(nlogn)

//Better-> create 3 variables cat0, cat1 , cat2 -> iterate over the loop and find the total counts for each variable.
// For each run a loop till it's value and overwrite the values in the og matirx -> 3 loops 
// Tc -> O(n+n) -> O(2n) Sc-> O(1)

// Best/ Optimized -> Dutch National flag algo -> 3 rules -> low , mid , high -> 
//0s -> 0 to low-1  1's ->  low to mid-1   2's -> high+1 to n-1   -> mid - high -> random values
// a[mid]= 0 -> swap(a[low],a[mid]), low++, mid++
// a[mid] = 1 -> mid ++
// a[high] = 2 -> swap(a[mid], a[high]), high++ 
// when mid> high -> array is sorted
// TC-> O(N)
class Solution {
    public:
    void sortColors(vector<int>& nums) 
    {
        int low = 0, mid = 0, high = nums.size() - 1;
    
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else if(nums[mid] == 2)
            {
                swap(nums[high],nums[mid]);
                high--;
            }
        }
    }
};
