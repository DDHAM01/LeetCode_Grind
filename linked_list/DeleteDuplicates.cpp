/*
  LeetCode 83 — Remove Duplicates from Sorted List
  -----------------------------------------------------
   Time Complexity:  O(n)
     - Traverses each node once.

   Space Complexity: O(1)
     - Constant auxiliary memory.
  Goal: Remove duplicate nodes from a sorted singly-linked list.
  The resulting list should contain only unique values.
*/

#include <bits/stdc++.h>
using namespace std;

/*
  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
*/
------------------------------------------------------
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while (temp && temp->next) {
            if (temp->val == temp->next->val) {
                ListNode* temp2 = temp->next;
                temp->next = temp2->next;
                delete temp2;   // manually free duplicate node memory
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};

