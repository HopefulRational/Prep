/*
Top K Frequent Elements
Solved

Given an integer array nums and an integer k, return the k most frequent elements within the array.

The test cases are generated such that the answer is always unique.

You may return the output in any order.

Example 1:

Input: nums = [1,2,2,3,3,3], k = 2

Output: [2,3]

*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto &x : nums) {
            m[x] += 1;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (const auto &elem : m) {
            pq.push({elem.second, elem.first});
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> res;
        while(pq.size()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
