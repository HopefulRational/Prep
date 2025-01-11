'''
Valid Anagram
Solved

Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: s = "racecar", t = "carrace"

Output: true

Example 2:

Input: s = "jar", t = "jam"

'''
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t): return False
        cnt = [0 for _ in range(26)]
        for i in range(len(s)):
            cnt[ord(s[i])-ord('a')] += 1
            cnt[ord(t[i])-ord('a')] -= 1
        return False if sum(cnt) > 0 else True
