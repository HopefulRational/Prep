/*
Valid Anagram

Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: s = "racecar", t = "carrace"

Output: true

Example 2:

Input: s = "jar", t = "jam"

Output: false

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int cnt[26] = {0};
        for(int i=0; i<s.size(); ++i) {
            cnt[s[i]-'a'] += 1;
            cnt[t[i]-'a'] -= 1;
        }
        for(auto &c: cnt)
            if(c) return false;
        return true;
    }

    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> mS, mT;
        for(int i=0; i<s.size(); ++i) {
            mS[s[i]] += 1;
            mT[t[i]] += 1;
        }
        return mS == mT;
    }
};