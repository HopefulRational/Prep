'''
Encode and Decode Strings
Solved

Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement encode and decode

Example 1:

Input: ["neet","code","love","you"]

Output:["neet","code","love","you"]

'''
class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ''
        for s in strs:
            res += str(len(s)) + '#' + s
        return res

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        while i < len(s):
            j = i+1
            while s[j] != '#':
                j += 1
            sz = int(s[i:j])
            j += 1
            res.append(s[j:j+sz])
            i = j+sz
        return res
