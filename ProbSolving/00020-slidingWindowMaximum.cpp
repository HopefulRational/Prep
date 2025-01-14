/*
Sliding Window Maximum
Solved

You are given an array of integers nums and an integer k. There is a sliding window of size k that starts at the left edge of the array. The window slides one position to the right until it reaches the right edge of the array.

Return a list that contains the maximum element in the window at each step.

Example 1:

Input: nums = [1,2,1,0,4,2,6], k = 3

Output: [2,2,4,4,6]

Explanation: 
Window position            Max
---------------           -----
[1  2  1] 0  4  2  6        2
 1 [2  1  0] 4  2  6        2
 1  2 [1  0  4] 2  6        4
 1  2  1 [0  4  2] 6        4
 1  2  1  0 [4  2  6]       6

Constraints:

    1 <= nums.length <= 1000
    -1000 <= nums[i] <= 1000
    1 <= k <= nums.length

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        for(int i=0; i<k-1; ++i) {
            pq.push({nums[i], i});
        }

        for(int i=k-1; i<nums.size(); ++i) {
            pq.push({nums[i],i});
            while(pq.size() and pq.top().second < i-k+1) pq.pop();
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};
