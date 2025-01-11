'''
Products of Array Except Self
Solved

Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

Each product is guaranteed to fit in a 32-bit integer.

Follow-up: Could you solve it in O(n)O(n) time without using the division operation?

Example 1:

Input: nums = [1,2,4,6]

Output: [48,24,12,8]

'''
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # can be optimized by using left and right lists but want
        # to do it this way as cpp code has optimized method
        res = []
        for i in range(len(nums)):
            res.append(self.listProd(nums[:i])*self.listProd(nums[i+1:]))
        return res
    
    def listProd(self, l: List[int]) -> int:
        res = 1
        for x in l:
            res *= x
        return res
        
