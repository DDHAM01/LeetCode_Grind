// Problem: Sqrt(x)
// LeetCode: https://leetcode.com/problems/sqrtx/
// Category: Math / Binary Search
// Approach 1: Linear Search (Brute Force)
// Difficulty: Easy
// Language: C++
// NOTES
// Binary is a better solution and reduces the time complexity to O(log n)

class Solution {
public:
    int mySqrt(int x) {
        int b = 0;

        for (long i = 0; i <= (long)x / 2 + 1; i++) {
            if (i * i == (long)x) {
                return i;
            } else if (i * i > (long)x) {
                return i - 1;
            }
        }

        return 0;
    }
};

// Time Complexity: O(sqrt(x))
// Space Complexity: O(1)

// Example:
// Input:  x = 8
// Output: 2
// Explanation: The square root of 8 is 2.828... which is truncated to 2.



/* ---------------------------------------------------------------
   ✅ OPTIMAL SOLUTION — Binary Search Approach
   ---------------------------------------------------------------
   Idea:
   - The square root must be between 0 and x/2 + 1.
   - Use binary search to find the largest integer whose square ≤ x.
   - Much faster than linear scan (O(log x) vs O(sqrt(x))).
*/

class SolutionOptimal {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        long left = 1, right = x / 2, ans = 0;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid < x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

// Time Complexity: O(log x)
// Space Complexity: O(1)



