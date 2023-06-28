// // Question ->
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.//

// Solution ->
class Solution {
public:
    bool revStr(string& sol, int i){
        int len=sol.length();
        
        if(i>=len/2) return true;
        else if (sol[i]!=sol[len-i-1]) return false;
        return revStr(sol, i+1);
    }

    bool isPalindrome(string s) {
        string sol;

        for(int i=0;i<s.length();i++){
            if(s[i]>='A'&&s[i]<='Z') sol.push_back(tolower(s[i]));
            else if(s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9') sol.push_back(s[i]);
        }
        return revStr(sol, 0);
    }
};
