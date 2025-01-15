/*
Evaluate Reverse Polish Notation
Solved

You are given an array of strings tokens that represents a valid arithmetic expression in Reverse Polish Notation.

Return the integer that represents the evaluation of the expression.

    The operands may be integers or the results of other operations.
    The operators include '+', '-', '*', and '/'.
    Assume that division between integers always truncates toward zero.

Example 1:

Input: tokens = ["1","2","+","3","*","4","-"]

Output: 5

Explanation: ((1 + 2) * 3) - 4 = 5

Constraints:

    1 <= tokens.length <= 1000.
    tokens[i] is "+", "-", "*", or "/", or a string representing an integer in the range [-100, 100].

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<float> stk;
        unordered_map<string, function<int(int, int)>> ops;
        ops["+"] = [](int a, int b) { return a+b; };
        ops["-"] = [](int a, int b) { return a-b; };
        ops["*"] = [](int a, int b) { return a*b; };
        ops["/"] = [](int a, int b) { return a/b; };
        for(auto &s : tokens) {
            if(ops.find(s) != ops.end()) {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                int val = ops[s](b,a);
                stk.push(val);
            }
            else {
                stk.push(atoi(s.c_str()));
            }
        }

        return stk.top();
    }
};
