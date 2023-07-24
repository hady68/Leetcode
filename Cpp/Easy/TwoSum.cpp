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


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create a hashmap and a result vector 
        // find complement in the mp if found return both index
        // if not found insert element in map with index
        // map will be <int,int> as we have to store an index


        unordered_map<int,int> mp;
        vector<int> result;


        for(int i=0; i<nums.size(); i++){

            int complement = target - nums[i];

            if(mp.find(complement)!=mp.end()){

                result.push_back(mp[complement]);
                result.push_back(i);
                break;
            }

            else{
                mp.insert({nums[i],i});
            }

        }

        return result;
    }
};
