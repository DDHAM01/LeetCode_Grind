# 🧩 LeetCode Grind  

Daily LeetCode grind where I solve algorithm problems in C++ to master data structures, algorithms, and prepare for technical interviews.  

---

## 📚 Topics Covered  
- Arrays & Strings  
- Linked Lists  
- Stacks & Queues  
- Trees & Graphs  
- Recursion & Backtracking  
- Dynamic Programming  
- Sorting & Searching  

---
---

## 🧠 Example  
**Problem:** [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)  
**Language:** C++  
**Approach:** Floyd’s Tortoise and Hare (slow and fast pointer)  
**Complexity:**  
- Time: O(n)  
- Space: O(1)  

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;  // base case
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;           // move 1 step
            fast = fast->next->next;     // move 2 steps
            if (slow == fast) return true; // pointers meet → cycle
        }
        return false;
    }
};
