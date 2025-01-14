/*
Valid Parentheses
Solved

You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

    Every open bracket is closed by the same type of close bracket.
    Open brackets are closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

Return true if s is a valid string, and false otherwise.

Example 1:

Input: s = "[]"

Output: true

Example 2:

Input: s = "([{}])"

Output: true

Example 3:

Input: s = "[(])"

Output: false

Explanation: The brackets are not closed in the correct order.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto &c : s) {
            // can use if-else instead of switch as well
            switch(c) {
                case '(':
                case '{':
                case '[': stk.push(c);
                          break;
                case ')': if(stk.empty() or stk.top() != '(') return false;
                          stk.pop();
                          break;
                case '}': if(stk.empty() or stk.top() != '{') return false;
                          stk.pop();
                          break;
                case ']': if(stk.empty() or stk.top() != '[') return false;
                          stk.pop();
                          break;
            }

        }
        return stk.empty();
    }
};
