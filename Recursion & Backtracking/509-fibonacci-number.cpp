// Problem: Fibonacci Number (LeetCode #509)
// Link: https://leetcode.com/problems/fibonacci-number/
// Time Complexity: O(2^n)
// Space Complexity: O(n)   // due to recursion stack
// Approach: Simple Recursion

// My Notes:
// - Directly applies the recurrence relation: F(n) = F(n-1) + F(n-2)
// - Works well for small n, but exponential growth in calls
// - Could be optimized using memoization or iteration (DP)

class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};

/*
-----------------------------------------------
 Optimal Solution (Dynamic Programming)
-----------------------------------------------
class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        int a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
*/
