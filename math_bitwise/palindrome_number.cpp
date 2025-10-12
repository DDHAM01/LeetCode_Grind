// Problem: Palindrome Number (LeetCode #9)
// Link: https://leetcode.com/problems/palindrome-number/
// Time Complexity: O(log₁₀(n))  // each loop removes one digit
// Space Complexity: O(1)
// Approach: Reverse the integer mathematically and compare with the original
// My Notes:
// - Negative numbers cannot be palindromes
// - Added overflow checks for both x and reverse
// - Did not convert integer to string (pure math-based solution)

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;

        int a = x;
        int remainder = 0;
        int reverse = 0;

        while (x != 0) {
            remainder = x % 10;
            x = x / 10;

            // Overflow checks (safe guard)
            if (x > INT_MAX / 10 || x < INT_MIN / 10)
                return false;
            if (reverse > INT_MAX / 10 || reverse < INT_MIN / 10)
                return false;

            reverse = reverse * 10 + remainder;
        }

        return reverse == a;
    }
};

/*
-----------------------------------------------
✅ Alternative Approach (Optimized Half-Reversal)
-----------------------------------------------
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int reversed = 0;
        while (x > reversed) {
            int digit = x % 10;
            x /= 10;
            reversed = reversed * 10 + digit;
        }
        return (x == reversed || x == reversed / 10);
    }
};
*/
