/*
Longest Consecutive Sequence
Solved

Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.

A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. The elements do not have to be consecutive in the original array.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [2,20,4,10,3,4,5]

Output: 4

Explanation: The longest consecutive sequence is [2, 3, 4, 5].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int ans = 1;
        for(auto &x : nums) {
            if(m.find(x) != m.end()) continue;
            auto prev = m.find(x-1);
            auto next = m.find(x+1);
            if(prev != m.end() and next != m.end()) {
                int p = m[x-1], n = m[x+1];
                m[(x-1)-p+1] = n+p+1;
                m[(x+1)+n-1] = n+p+1;
                m[x] = n+p+1;
                ans = max(ans, n+p+1);
            }
            else if(next != m.end()) {
                int n = m[x+1];
                m[(x+1)+n-1] = n+1;
                m[x] = n+1;
                ans = max(ans, n+1);
            }
            else if(prev != m.end()) {
                int p = m[x-1];
                m[(x-1)-p+1] = p+1;
                m[x] = p+1;
                ans = max(ans, p+1);
            }
            else {
                m[x] = 1;
            }
        }

        return nums.size() ? ans : 0;
    }

    int longestConsecutiveV2(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());

        int largest = 0;
        for(auto &n : nums) {
            if(s.find(n-1) == s.end()) {
                int len = 1;
                while(s.find(n+len) != s.end()) {
                    ++len;
                }
                largest = max(largest, len);
            }
        }

        return largest;
    }

    int longestConsecutiveV3(vector<int>& nums) {
        unordered_map<int, int> m;
        int res = 0;

        for(int &x : nums) {
            if(!m[x]) {
                m[x] = m[x-1]+m[x+1]+1;
                m[x-m[x-1]] = m[x];
                m[x+m[x+1]] = m[x];
                res = max(res, m[x]);
            }
        }

        return res;
    }
};
