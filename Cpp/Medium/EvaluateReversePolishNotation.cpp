// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Evaluate the expression. Return an integer that represents the value of the expression.

// Note that:

// The valid operators are '+', '-', '*', and '/'.
// Each operand may be an integer or another expression.
// The division between two integers always truncates toward zero.
// There will not be any division by zero.
// The input represents a valid arithmetic expression in a reverse polish notation.
// The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:

// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6
// Example 3:

// Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// Output: 22
// Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22


/*
    Evaluate RPN, valid operators: +, -, *, /

    Stack, if num push, if operator apply to top 2 nums

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> store;
        
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];
            
            if (token.size() > 1 || isdigit(token[0])) {
                store.push(stoi(token));
                continue;
            }
            
            int num2 = store.top();
            store.pop();
            int num1 = store.top();
            store.pop();
            
            int result = 0;
            if (token == "+") {
                result = num1 + num2;
            } else if (token == "-") {
                result = num1 - num2;
            } else if (token == "*") {
                result = num1 * num2;
            } else {
                result = num1 / num2;
            }
            store.push(result);
        }
        
        return store.top();
    }
};


// Using Vector instead of stack
// TC -> O(n) Sc -> O(1)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
	int top = 0;
	for(int i= 0; i<tokens.size(); i++)
    {
        string t = tokens[i];
		if(t == "+" || t == "-" || t == "*" || t == "/") {
			int op1 = stoi(tokens[--top]); 
			int op2 = stoi(tokens[--top]); 
			if(t == "+") op1 = op2 + op1;
			if(t == "-") op1 = op2 - op1;
			if(t == "/") op1 = op2 / op1;
			if(t == "*") op1 = op2 * op1;   
			tokens[top++] = to_string(op1);
		}
		else tokens[top++] = t;
    } 

	return stoi(tokens[0]);
}
            
};
