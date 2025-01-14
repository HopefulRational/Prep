/*
Two Integer Sum II
Solved

Given an array of integers numbers that is sorted in non-decreasing order.

Return the indices (1-indexed) of two numbers, [index1, index2], such that they add up to a given target number target and index1 < index2. Note that index1 and index2 cannot be equal, therefore you may not use the same element twice.

There will always be exactly one valid solution.

Your solution must use O(1)O(1) additional space.

Example 1:

Input: numbers = [1,2,3,4], target = 3

Output: [1,2]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int idx1 = 0, idx2 = numbers.size()-1;
        while(idx1 < idx2) {
            if(numbers[idx1] + numbers[idx2] == target) 
                return {idx1+1, idx2+1};
            else if(numbers[idx1] + numbers[idx2] > target)
                idx2 -= 1;
            else
                idx1 += 1;
        }
        return {-1, -1};
    }
};
