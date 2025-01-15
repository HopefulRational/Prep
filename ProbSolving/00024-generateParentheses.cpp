/*
Generate Parentheses
Solved

You are given an integer n. Return all well-formed parentheses strings that you can generate with n pairs of parentheses.

Example 1:

Input: n = 1

Output: ["()"]

Example 2:

Input: n = 3

Output: ["((()))","(()())","(())()","()(())","()()()"]

You may return the answer in any order.

Constraints:

    1 <= n <= 7

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void generate(vector<string> &ans, string &s, int open, int closed, int n) {
        if(s.size() == 2*n) {
            ans.push_back(s);
            return;
        }
        if(open < n) {
            s.push_back('(');
            generate(ans, s, open+1, closed, n);
            s.pop_back();
        }
        if(closed < open) {
            s.push_back(')');
            generate(ans, s, open, closed+1, n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        generate(ans, s, 0, 0, n);
        return ans;
    }
};
