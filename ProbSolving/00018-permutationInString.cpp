/*
Permutation in String
Solved

You are given two strings s1 and s2.

Return true if s2 contains a permutation of s1, or false otherwise. That means if a permutation of s1 exists as a substring of s2, then return true.

Both strings only contain lowercase letters.

Example 1:

Input: s1 = "abc", s2 = "lecabee"

Output: true

Explanation: The substring "cab" is a permutation of "abc" and is present in "lecabee".
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        unordered_map<char, int> m1, m2;
        for(auto &c : s1) ++m1[c];
        int l=0, r=0;
        while(r<s1.size()) ++m2[s2[r++]];
        while(r<s2.size()) {
            if(m1 == m2) return true;
            ++m2[s2[r++]];
            if(--m2[s2[l++]] == 0) {
                m2.erase(s2[l-1]);
            }
        }
        return m1 == m2;
    }
    void print(unordered_map<char,int> &myMap) {
        std::cout << "{ ";
        std::for_each(myMap.begin(), myMap.end(), [](const auto& pair) {
            std::cout << "(" << pair.first << ": " << pair.second << ") ";
        });
        std::cout << "}" << std::endl;
    }
    void print(vector<int> &numbers) {
        std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, " "));
    }
};
