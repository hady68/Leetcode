// You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

// Given the string command, return the Goal Parser's interpretation of command.

 

// Example 1:

// Input: command = "G()(al)"
// Output: "Goal"
// Explanation: The Goal Parser interprets the command as follows:
// G -> G
// () -> o
// (al) -> al
// The final concatenated result is "Goal".
// Example 2:

// Input: command = "G()()()()(al)"
// Output: "Gooooal"
// Example 3:

// Input: command = "(al)G(al)()()G"
// Output: "alGalooG"
 

// Constraints:

// 1 <= command.length <= 100
// command consists of "G", "()", and/or "(al)" in some order.

// Brute force -> loop and if else -> // Time: O(N) // Space: O(1) extra space
class Solution {
public:
    string interpret(string command) {
        string result;
        int i = 0;

        while (i < command.size()) {
            if (command[i] == 'G') {
                result += 'G';
                i++;
            } else if (command[i] == '(') {
                if (command[i + 1] == 'a') {
                    result += "al";
                    i += 4; // Skip "al)"
                } else {
                    result += 'o';
                    i += 2; // Skip "()"
                }
            }
        }

        return result;
    }
};

