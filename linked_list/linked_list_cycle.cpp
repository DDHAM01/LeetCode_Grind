// Problem: Linked List Cycle (LeetCode #141)
// Link: https://leetcode.com/problems/linked-list-cycle/
// Time Complexity: O(n)
// Space Complexity: O(1)
// Approach: Floyd’s Tortoise and Hare (slow & fast pointers)

// My Notes:
// - First tried iterative pointer advance (custom version)
// - Optimized to standard Floyd’s cycle detection for clarity

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // My Implementation
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            if (temp == nullptr) return false;
            temp = temp->next;
            head = head->next;
            if (head == temp) return true;
        }
        return false;
    }
};

/*
-----------------------------------------------
 Optimal Solution (Same Logic)
-----------------------------------------------
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
*/
