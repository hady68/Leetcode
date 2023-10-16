// Problem Statement
// Detailed explanation ( Input/output format, Notes, Images )
// Sample Input 1:
// abbba
// Sample Output 1:
// true
// Explanation Of Sample Input 1 :
// “abbba” is a palindrome
// Sample Input 2:
// abcd
// Sample Output 2:
// false
// Explanation Of Sample Input 2 :
// “abcd” is not a palindrome.
// Constraints:
// 0 <= |S| <= 10^6
// where |S| represents the length of string S.

// Brute -> use Reverse function in STL
bool checkPalindrome(bool& ans, string& str){
    string reversed = str;
    reverse(reversed.begin(), reversed.end());
    if(str == reversed)
    ans = true;
    return ans;
}
bool isPalindrome(string& str) {
    // Write your code here.
    bool ans = false;
    checkPalindrome(ans,str);
    return ans;
}

// Via two pointers
bool isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

// Via Recursion => Two pointers
bool checkPalindrome(string& str, int left, int right){
    if(left>=right){
        return true;
    }
    if(str[left]== str[right]){
        return checkPalindrome(str, left+1, right-1);
    }
    return false;
}
bool isPalindrome(string& str) {
   
    // recursive sol via two pointers
    return checkPalindrome(str,0,str.length()-1);
}
