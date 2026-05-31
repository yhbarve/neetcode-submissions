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
    ListNode* reverseList(ListNode* head) {
        ListNode* reverseHead = nullptr;
        ListNode* cur = head;

        while (cur){
            ListNode* temp = cur->next;
            cur->next = reverseHead;
            reverseHead = cur;
            cur = temp;
        }

        return reverseHead;
    }
};
