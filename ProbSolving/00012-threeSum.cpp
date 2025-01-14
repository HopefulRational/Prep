/*
3Sum
Solved

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.

The output should not contain any duplicate triplets. You may return the output and the triplets in any order.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]

Output: [[-1,-1,2],[-1,0,1]]

Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].

Example 2:

Input: nums = [0,1,1]

Output: []

Explanation: The only possible triplet does not sum up to 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        // requres -std=c++20
        // ranges::sort(nums);
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] > 0) break;
            if(i>0 and nums[i] == nums[i-1]) continue;
            int l=i+1, r=nums.size()-1;
            while(l < r) {
                int sm = nums[i] + nums[l] + nums[r];
                if(sm > 0) {
                    --r;
                }
                else if(sm < 0) {
                    ++l;
                }
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                    while(l<r and nums[l] == nums[l-1]) ++l;
                    while(l<r and nums[r] == nums[r+1]) --r;
                }
            }
        }

        return res;
    }
    vector<vector<int>> threeSumV2(vector<int>& nums) {
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i] > 0) break;
            if(i>0 and nums[i] == nums[i-1]) continue;
            int l = i+1, r=nums.size()-1;
            while(l < r) {
                // Note: l>(i+1) and not l>1
                // since for [-1,-1,..], l=1(ie nums[l]=-1)
                // needs to considered
                if(l>(i+1) and nums[l] == nums[l-1]) {
                    ++l;
                    continue;
                }
                if(r<(nums.size()-1) and nums[r] == nums[r+1]) {
                    --r;
                    continue;
                }
                int t = nums[l]+nums[r];
                if(t == -nums[i]) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    --r;
                }
                else if(t > -nums[i]) {
                    --r;
                }
                else {
                    ++l;
                }
            }
        }

        return res;
    }
};
