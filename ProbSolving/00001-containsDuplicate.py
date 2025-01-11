'''
Contains Duplicate

Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

Example 1:

Input: nums = [1, 2, 3, 3]

Output: true


Example 2:

Input: nums = [1, 2, 3, 4]

Output: false
'''
class Solution:
    def containsDuplicateV1(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums))
    
    def containsDuplicateV2(self, nums: List[int]) -> bool:
        s = set()
        for x in nums:
            if x in s: return true
            s.add(x)
        return False
