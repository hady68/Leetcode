// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
//https://leetcode.com/problems/two-sum/description/

//Solution -> Brute force (O)n^2 complexity -> using 2 for loops
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>store;
        // brute force using 2 loops 
        for(int i=0; i<nums.size();i++){
            for(int j=i+1; j<nums.size();j++){ 
                if(nums[i] + nums[j]  == target){
                    store.push_back(i);
                    store.push_back(j);
                    return store;
                }
            }
        }
            return store;
    }
};


//  Using map -> findind the complement of target if nums[i] and looking it up in that map while populating the map as well
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // target sum => i + j also i= target -j 
        // for each i check if target - i = j exsits if yes then true

        unordered_map<int,int> m;
        vector<int> result;
        
        // run a loop to check for each 
        for(int i =0; i<nums.size();i++){
            int complement = target - nums[i];
            if(m.find(complement) != m.end()){
                result.push_back(m[complement]);
                result.push_back(i);
            break;
            } 
            else {
                m.insert({nums[i], i});
            }

        }
            
              return result;

    }
};
