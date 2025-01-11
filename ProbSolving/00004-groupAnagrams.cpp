/*
Group Anagrams
Solved

Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: strs = ["act","pots","tops","cat","stop","hat"]

Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto &s : strs) {
            int cnt[26] = {0};
            for(auto c : s)
                cnt[c-'a'] += 1;
            string t = to_string(cnt[0]);
            for(int i=1; i<26; ++i)
                t += ',' + to_string(cnt[i]);
            m[t].push_back(s);
        }
        vector<vector<string>> res;
        for(const auto& elem : m)
            res.push_back(elem.second);
        return res;
    }
};