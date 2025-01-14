/*
Minimum Window Substring
Solved

Given two strings s and t, return the shortest substring of s such that every character in t, including duplicates, is present in the substring. If such a substring does not exist, return an empty string "".

You may assume that the correct output is always unique.

Example 1:

Input: s = "OUZODYXAZV", t = "XYZ"

Output: "YXAZ"

Explanation: "YXAZ" is the shortest substring that includes "X", "Y", and "Z" from string t.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int numChars=0, matched=0, i=0, cnt=s.size()+1, l=0, r=0;
        unordered_map<char, int> ms, mt;
        for(auto &c : t) {
            if(mt[c] == 0) ++numChars;
            ++mt[c];
        }
        for(; r<s.size(); ++r) {
            if(++ms[s[r]] == mt[s[r]]) ++matched;
            if(matched == numChars) {
                while(ms[s[l]] > mt[s[l]]) {
                    --ms[s[l++]];
                }
                if(r-l+1 < cnt) {
                    cnt = r-l+1;
                    i = l;
                }
                if(--ms[s[l]] < mt[s[l++]]) --matched;
            }
        }

        return cnt == s.size()+1 ? "" : s.substr(i,cnt);
    }
    string minWindowV2(string s, string t) {
        unordered_map<char, int> ms, mt;
        for(auto &c : t) ++mt[c];
        int l=0, r=0, ans=s.size()+1, i=0;
        for(; r < s.size(); ++r) {
            ++ms[s[r]];
            while(l<r and ms[s[l]] > mt[s[l]]) {
                --ms[s[l++]];
            }
            bool allPresent = true;
            for(auto &p : mt) {
                if(ms[p.first] < p.second) {
                    allPresent = false;
                    break;
                }
            }
            if(allPresent) {
                ans = min(ans, r-l+1);
                i=l;
            }
        }
        return ans == s.size()+1 ? "" : s.substr(i,ans);
    }
};
