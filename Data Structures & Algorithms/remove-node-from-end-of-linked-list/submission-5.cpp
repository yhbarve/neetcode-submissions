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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
            1, 2, 3, 4 | n = 2
                  p  p  p 
            q  q  q               

        */

        ListNode* p = head;
        ListNode* q = head;
        ListNode* prev = new ListNode(0);
        ListNode* sol = prev;
        prev->next = head;

        // move p 'n' steps forward
        for (int i = 0; i < n; i++){
            p = p->next;
        }

        // move both p & q forward till p is out of bounds
        while (p){
            p = p->next;
            prev = prev->next;
            q = q->next;
        }

        // q is the node to eliminate
        if (prev){
            prev->next = q->next;
        }

        return sol->next;
    }
};
