// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
// You must implement a solution with O(1) time complexity for each function.

// Example 1:
// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
 
// Constraints:
// -231 <= val <= 231 - 1
// Methods pop, top and getMin operations will always be called on non-empty stacks.
// At most 3 * 104 calls will be made to push, pop, top, and getMin.


// Implemeted using 2 stacks 1 storing the values and the other storing the min value so far 
class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};

// using vector 
class MinStack {
private:
    vector<int> s1;
    vector<int> s2;
public:
    void push(int x) {
	    s1.push_back(x);
	    if (s2.empty() || x <= getMin())  s2.push_back(x);	    
    }
    void pop() {
	    if (s1.back() == getMin())  s2.pop_back();
	    s1.pop_back();
    }
    int top() {
	    return s1.back();
    }
    int getMin() {
	    return s2.back();
    }
};
