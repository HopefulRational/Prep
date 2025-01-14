/*
Trapping Rain Water
Solved

You are given an array non-negative integers height which represent an elevation map. Each value height[i] represents the height of a bar, which has a width of 1.

Return the maximum area of water that can be trapped between the bars.

Example 1:

Input: height = [0,2,0,3,1,0,1,3,2,1]

Output: 9

Constraints:

    1 <= height.length <= 1000
    0 <= height[i] <= 1000

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& heights) {
        int ans = 0;
        int l = 0, r = heights.size()-1;
        int leftmax = heights[l], rightmax = heights[r];
        while(l < r) {
            if(leftmax < rightmax) {
                ++l;
                leftmax = max(leftmax, heights[l]);
                ans += leftmax - heights[l];
            }
            else {
                --r;
                rightmax = max(rightmax, heights[r]);
                ans += rightmax - heights[r];
            }
        }

        return ans;
    }
    int trapV2(vector<int>& heights) {
        stack<int> stk;
        int ans = 0;
        for(int i=0; i<heights.size(); ++i) {
            while(stk.size() and heights[i] >= heights[stk.top()]) {
                int mid = heights[stk.top()];
                stk.pop();
                if(stk.size()) {
                    int left = heights[stk.top()];
                    int right = heights[i];
                    int h = min(left, right) - mid;
                    int w = i - stk.top() - 1;
                    ans += h * w;
                }
            }
            stk.push(i);
        }

        return ans;
    }
};
