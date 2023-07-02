// // quetion 
// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// solution 1 - sorting TC -> 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        // sort array and check next elements
        if(nums.size()<1){
            return false;
        }
         sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++){

            if(nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;
    }
};

// Solution 2 -> Hashset -> TC - O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num) > 0)
                return true;
            seen.insert(num);
        }
        return false;
    }
};


// Soln 3 -> Hashmap -> O(n) but keeps count of each element as well
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int num : nums) {
            if (seen[num] >= 1){

                return true;
            }
            seen[num]++;
        }
        return false;
    }
};
