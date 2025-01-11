'''
Group Anagrams
Solved

Given an array of strings strs, group all anagrams together into sublists. You may return the output in any order.

An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

Example 1:

Input: strs = ["act","pots","tops","cat","stop","hat"]

Output: [["hat"],["act", "cat"],["stop", "pots", "tops"]]

'''
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = defaultdict(list)
        for i in range(len(strs)):
            l = [0 for _ in range(26)]
            for c in strs[i]:
                l[ord(c)-ord('a')] += 1
            d[str(l)].append(i)
        res = []
        for l in d:
            s = []
            for i in d[l]:
                s.append(strs[i])
            res.append(s)
        return res