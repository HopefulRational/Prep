/*
Products of Array Except Self
Solved

Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

Each product is guaranteed to fit in a 32-bit integer.

Follow-up: Could you solve it in O(n)O(n) time without using the division operation?

Example 1:

Input: nums = [1,2,4,6]

Output: [48,24,12,8]

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // it is better to init vector to desired size
        vector<int> left, right;
        
        left.push_back(1);
        for (int i=1; i<nums.size(); ++i) {
            left.push_back(left.back() * nums[i-1]);
        }

        right.push_back(1);
        for(int i=nums.size()-2; i>=0; --i) {
            right.push_back(right.back() * nums[i+1]);
        }
        reverse(right.begin(), right.end());

        vector<int> ans;
        for(int i=0; i<nums.size(); ++i) {
            ans.push_back(left[i] * right[i]);
        }

        return ans;
    }
};
