/*
Valid Palindrome
Solved

Given a string s, return true if it is a palindrome, otherwise return false.

A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

Example 1:

Input: s = "Was it a car or a cat I saw?"

Output: true

Explanation: After considering only alphanumerical characters we have "wasitacaroracatisaw", which is a palindrome.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(char &c : s)
            if(isalnum(c))
                t.push_back(tolower(c));
        for(int i=0, n=t.size(); i<n/2; ++i) {
            if(t[i] != t[n-1-i]) return false;
        }
        return true;
    }
    bool isPalindromeV2(string s) {
        int i=0, j=s.size()-1;
        while(i < j)
        {
            if(isalnum(s[i]) and isalnum(s[j])) {
                if(tolower(s[i]) != tolower(s[j])) return false;
                else ++i, --j;
            }
            else {
                if(!isalnum(s[i])) ++i;
                if(!isalnum(s[j])) --j;
            }

        }
        return true;
    }
};
