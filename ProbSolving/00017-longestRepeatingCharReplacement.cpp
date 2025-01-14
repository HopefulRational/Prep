/*
Longest Repeating Character Replacement
Solved

You are given a string s consisting of only uppercase english characters and an integer k. You can choose up to k characters of the string and replace them with any other uppercase English character.

After performing at most k replacements, return the length of the longest substring which contains only one distinct character.

Example 1:

Input: s = "XYYX", k = 2

Output: 4

Explanation: Either replace the 'X's with 'Y's, or replace the 'Y's with 'X's.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=0, l=0, r=0, maxf=0;
        unordered_map<char, int> m;
        for(; r<s.size(); ++r) {
            maxf = max(maxf, ++m[s[r]]);
            while((r-l+1)-maxf > k) {
                --m[s[l++]];
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
    int characterReplacementV2(string s, int k) {
        int ans = 0;
        unordered_map<char, int> m;
        int l=0, r=0;
        for(; r < s.size(); ++r) {
            ++m[s[r]];
            int maxcnt = 0;
            for(auto &[c,cnt] : m) {
                maxcnt = max(maxcnt, cnt);
            }
            while((r-l+1)-maxcnt > k) {
                --m[s[l++]];
                int maxcnt = 0;
                for(auto &[c,cnt] : m) {
                    maxcnt = max(maxcnt, cnt);
                }
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
