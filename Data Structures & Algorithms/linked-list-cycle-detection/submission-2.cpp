/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr) return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr){
            // To access fast->next->next, we need fast & fast->next to be not null
            // If fast exists, then so does slow because it lags behind fast
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) return true;
        }
        return false;
    }
};