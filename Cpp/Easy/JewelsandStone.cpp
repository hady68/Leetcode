// You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

// Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

// Example 1:

// Input: jewels = "aA", stones = "aAAbbbb"
// Output: 3
// Example 2:

// Input: jewels = "z", stones = "ZZ"
// Output: 0
 

// Constraints:

// 1 <= jewels.length, stones.length <= 50
// jewels and stones consist of only English letters.
// All the characters of jewels are unique.

// brute force -> using 2 loops checking the stones arr if jewels is there 
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
       // for each stone check if a jewel
        int count = 0;
       for(int i=0; i<stones.size(); i++){

           for(int j=0; j<jewels.size(); j++){
               if (stones[i] == jewels[j])
               count++;
           }
       }
       return count;
    }
};

// better -> using a hashmap 
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
      int ans=0; 
    map<char,int>count;

    //counting all stones
    for(int i=0;i<stones.size();i++)
        count[stones[i]]++;          

    //sum all valid jewels stone
    for(int i=0;i<jewels.size();i++)
        ans+=count[jewels[i]];           

    return ans;
    }
};    
