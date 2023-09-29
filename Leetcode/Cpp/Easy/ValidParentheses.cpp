// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false

// Constraints:
// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

// Brute force ->  using 2 loops check for each open parenthesis with the closed parenthesis  O(n^2) time.

//Optimal -> Using a stack to fill it up with open parenthesis, and then store the top element in a variable and then remove it of it matches the open bracket.
// if the stack is empty then it is true otherwise false;

class Solution {
  public: bool isValid(string s) {
      // creating a stack 
    stack < char > valid;
    // iterate the loop
    for (char x: s) {
        // check for open parenthesis and push it in stack
      if (x =='(' || x =='{' || x =='[') {
        valid.push(x);
      } else {
          // if no open brackets then dont psuh return false
        if (valid.empty()) {
          return false;
        }
        char temp = valid.top();
        valid.pop();
        if (temp == '(' && x == ')')
          continue;
        else if (temp == '[' && x == ']')
          continue;
        else if (temp == '{' && x == '}')
          continue;
        return false;
      }
    }
    if (valid.empty()) {
      return true;
    } else {
      return false;
    }
  }

};
