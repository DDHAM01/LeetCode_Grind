// Problem: Roman to Integer (LeetCode #13)
// Link: https://leetcode.com/problems/roman-to-integer/
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Manual parsing with subtractive pair checks
// My Notes:
// - Built my own logic for handling all Roman numeral pairs manually
// - Used nested conditions for 'I', 'X', and 'C' to detect subtractive cases
// - Learned how Roman numerals combine through offset adjustments (+3, +8, etc.)
// - Below this is the more optimal version using direct comparison logic

class Solution {
public:
    int romanToInt(string s) {
        int a = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'I') {
                a += 1;
                if (i + 1 < s.length()) {
                    if (s[i + 1] == 'V') {
                        a += 3;
                        i++;
                    } else if (s[i + 1] == 'X') {
                        a += 8;
                        i++;
                    }
                }
            }
            else if (s[i] == 'V') {
                a += 5;
            }
            else if (s[i] == 'X') {
                a += 10;
                if (i + 1 < s.length()) {
                    if (s[i + 1] == 'L') {
                        a += 30;
                        i++;
                    } else if (s[i + 1] == 'C') {
                        a += 80;
                        i++;
                    }
                }
            }
            else if (s[i] == 'L') {
                a += 50;
            }
            else if (s[i] == 'C') {
                a += 100;
                if (i + 1 < s.length()) {
                    if (s[i + 1] == 'D') {
                        a += 300;
                        i++;
                    } else if (s[i + 1] == 'M') {
                        a += 800;
                        i++;
                    }
                }
            }
            else if (s[i] == 'D') {
                a += 500;
            }
            else if (s[i] == 'M') {
                a += 1000;
            }
        }
        return a;
    }
};

/*
-----------------------------------------------
✅ Optimal Solution (Mathematical Comparison)
-----------------------------------------------
#include <string>
using std::string;

class Solution {
public:
    int getValueForChar(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }

    int romanToInt(string s) {
        int retVal = 0;
        for (int i = 0; i < s.size(); ++i) {
            int current = getValueForChar(s[i]);
            int next = (i + 1 < s.size()) ? getValueForChar(s[i + 1]) : 0;
            retVal += (current < next) ? -current : current;
        }
        return retVal;
    }
};
*/
