/*
Longest Substring Without Repeating Characters
Solved

Given a string s, find the length of the longest substring without duplicate characters.

A substring is a contiguous sequence of characters within a string.

Example 1:

Input: s = "zxyzxyz"

Output: 3

Explanation: The string "xyz" is the longest without duplicate characters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ss;
        int l=0, r=0, ans=0;
        while(r < s.size()) {
            while(ss.find(s[r]) != ss.end()) {
                ss.erase(s[l++]);
            }
            ss.insert(s[r++]);
            ans = max(ans, int(ss.size()));
            
        }
        return ans;
    }
};
