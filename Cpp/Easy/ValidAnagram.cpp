// question
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false

// https://leetcode.com/problems/valid-anagram
 
// Solution using 2 hashmaps 
class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.size() != t.size()){
       return false;
      }

     unordered_map<char,int>smapped;
     unordered_map<char,int>tmapped;

     for(int i = 0; i<s.size(); i++){
      smapped[s[i]]++;
      tmapped[t[i]]++;
     }

     for(int i=0; i<s.size();i++){

   if(smapped[i]! tmapped[i]) return false;     
     }
     return true;
    }
};




// Solution using single hashmap 
class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> counts;
     // Increment the count of each character in string s
        for (char ch : s) {
            counts[ch]++;
        }
     // Decrement the count of each character in string t
        for (char ch : t) {
            counts[ch]--;
        }
     // If all counts are zero, it is an anagram
        for (const auto& pair : counts) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true;

     }
};
