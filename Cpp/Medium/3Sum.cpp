// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

// Example 2:
// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

//Brute Force -> Use 3 pointers and 3 loops to check if they are equal to the value
//Time Complexity : O(n^3)   // 3 loops
//Space Complexity : O(3*k)  // k is the no.of triplets

vector < vector < int >> threeSum(vector < int > & nums) {
  vector < vector < int >> ans;
  vector < int > temp;
  int i, j, k;
  for (i = 0; i < nums.size() - 2; i++) {
    for (j = i + 1; j < nums.size() - 1; j++) {
      for (k = j + 1; k < nums.size(); k++) {
        temp.clear();
        if (nums[i] + nums[j] + nums[k] == 0) {
          temp.push_back(nums[i]);
          temp.push_back(nums[j]);
          temp.push_back(nums[k]);
        }
        if (temp.size() != 0)
          ans.push_back(temp);
      }
    }
  }

  return ans;
}


// Better TC-> O(N^2) SC-> O(n)+O(unique triplets)*2  -> in the previous approach we calculated a[i]+a[j]+a[k] = 0; here we take a[k] = -(a[i]+a[j])
// we find this value  using 2 loops and we store the existing values for i to j in a hashset,
// we check if the complement is present, then we sort it and push it to the ans set as only unique sets are required.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    // set to store the distinct triplets
     set<vector<int>> st;
     // check the 2 values nums[k] = -(nums[i] + nums[j])
     for(int i=0; i<nums.size(); i++){
         // initialzie for every value as initially set will be empty
         set<int> hashset;
         for(int j=i+1; j<nums.size(); j++){
                int third  = -(nums[i] + nums[j]);

                // find this value in the hashset 
                // if not point to the end of hashset means it is there in the set
               if( hashset.find(third)!= hashset.end()){
                   // it is a triplet 

                   vector<int> temp = {nums[i], nums[j], third};

                   // sort it 
                   sort(temp.begin(),temp.end());

                   // it has to store unique
                   st.insert(temp);
               }
                // add each value into the set
                 hashset.insert(nums[j]);

         }
     }

    // pushing the unique set values into the ans vector 
    vector<vector<int>> ans.(st.begin(), st.end());
    return ans;
        


    }
};

BEST -> Using
