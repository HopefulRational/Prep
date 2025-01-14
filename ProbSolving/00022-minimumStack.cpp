/*
Minimum Stack
Solved

Design a stack class that supports the push, pop, top, and getMin operations.

    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.

Each function should run in O(1)O(1) time.

Example 1:

Input: ["MinStack", "push", 1, "push", 2, "push", 0, "getMin", "pop", "top", "getMin"]

Output: [null,null,null,null,0,null,2,1]

Explanation:
MinStack minStack = new MinStack();
minStack.push(1);
minStack.push(2);
minStack.push(0);
minStack.getMin(); // return 0
minStack.pop();
minStack.top();    // return 2
minStack.getMin(); // return 1

Constraints:

    -2^31 <= val <= 2^31 - 1.
    pop, top and getMin will always be called on non-empty stacks.

*/

#include<bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long> stk;
    long Min;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty()) {
            stk.push(0);
            Min = val;
        }
        else {
            stk.push(val - Min);
            if(val < Min) Min = val;
        }
    }
    
    void pop() {
        if(stk.empty()) return;
        long val = stk.top();
        stk.pop();
        if(val < 0) Min = Min - val;
    }
    
    int top() {
        long val = stk.top();
        return (val > 0) ? int(val + Min) : int(Min);
    }
    
    int getMin() {
        return int(Min);
    }
};

class MinStackV2 {
    stack<int> stk, Min;
    public:
        MinStackV2() {
            
        }
        
        void push(int val) {
            stk.push(val);
            if(Min.empty()) Min.push(val);
            else Min.push(min(Min.top(), val));
        }
        
        void pop() {
            stk.pop();
            Min.pop();
        }
        
        int top() {
            return stk.top();
        }
        
        int getMin() {
            return Min.top();
        }
};
