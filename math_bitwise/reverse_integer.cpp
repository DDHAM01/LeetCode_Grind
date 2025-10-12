// Problem: Reverse Integer (LeetCode #7)
// Link: https://leetcode.com/problems/reverse-integer/
// Time Complexity: O(n)  // proportional to number of digits
// Space Complexity: O(n) // uses string storage
// Approach: Convert integer to string, reverse it, handle sign and overflow
// My Notes:
// - My original string-based approach (learned early on)
// - Handles negatives manually and checks overflow
// - I now also understand the mathematical version using modulus (%10) and division (/10)
//   → where you extract digits, build a reversed integer, and check overflow using INT_MAX/INT_MIN limits
// - Keeping both for comparison and learning progression

class Solution {
public:
    int reverse(int x) {
        string reverse;
        string a = to_string(x);
        int sign = -1;

        if (x > INT_MAX - 1 || x < INT_MIN + 1) {
            return 0;
        }

        if (x < 0) {
            x = sign * x;
        } else {
            sign = 1;
        }

        for (int i = a.length() - 1; i >= 0; i--) {
            reverse += a[i];
        }

        long long valid = stoll(reverse);
        if (valid > INT_MAX) {
            return 0;
        }

        return sign * (int)valid;
    }
};

/*
-----------------------------------------------
✅ Alternative Solution (Mathematical Approach)
-----------------------------------------------
class Solution {
public:
    int reverse(int x) {
        long reversed = 0;
        while (x != 0) {
            int digit = x % 10;    // extract last digit
            x /= 10;               // remove last digit
            reversed = reversed * 10 + digit; // build reversed
            if (reversed > INT_MAX || reversed < INT_MIN)
                return 0;
        }
        return (int)reversed;
    }
};
*/
