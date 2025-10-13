// Problem: Remove Element
// LeetCode: https://leetcode.com/problems/remove-element/
// Category: Arrays & Strings
// Approach: Two Pointer (In-Place Overwrite)
// Difficulty: Easy
// Language: C++

#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // position for next valid element
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

// Example:
// Input:  nums = [3,2,2,3], val = 3
// Output: 2
// Explanation: Function should return k = 2, with the first two elements = [2,2].
