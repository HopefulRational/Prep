/*
Container With Most Water
Solved

You are given an integer array heights where heights[i] represents the height of the ithith bar.

You may choose any two bars to form a container. Return the maximum amount of water a container can store.

Example 1:

Input: height = [1,7,2,5,4,7,3,6]

Output: 36

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0, r=heights.size()-1;
        int ans = 0;
        while(l < r) {
            int area = (r-l)*min(heights[l], heights[r]);
            ans = max(ans, area);
            if(heights[l] < heights[r]) {
                ++l;
            }
            else {
                --r;
            }
        }
        return ans;
    }
};
