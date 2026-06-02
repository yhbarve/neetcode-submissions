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
    ListNode* reverse(ListNode* head){
        ListNode* revHead = nullptr;
        while (head){
            ListNode* temp = head->next;
            head->next = revHead;
            revHead = head;
            head = temp;
        }
        return revHead;
    }

    void reorderList(ListNode* head) {
        if (head->next == nullptr) return;
        /*
            0, 1, 2, 3, 4, 5, 6
            s  s  s  s            
            f     f     f     f

            0, 1, 2 | 3, 4, 5, 6
            0, 1, 2 | 6, 5, 4, 3
            0, 6, 1, 5, 2, 4, 3


            2, 4, 6, 8
            s  s  s     
            f     f    f
            2, 4 | 6, 8
            2, 4 | 8, 6
            2, 8, 4, 6

            #1: Split the list in half
            #2: Reverse the right half
            #3: Merge alternatively
        */

        // #1
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while (fast && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        // slow = right half

        if (prev){
            prev->next = nullptr;
            // disconnect the left & right halves
        }

        // #2
        ListNode* right = reverse(slow);
        cout << "Haha " << endl;

        // #3
        ListNode* cur = head;
        ListNode* left = head;
        while(left && right){
            ListNode* leftNext = left->next;
            ListNode* rightNext = right->next;
            left->next = right;
            if (leftNext == nullptr) break;
            right->next = leftNext;
            left = leftNext;
            right = rightNext;
        }
        return;
    }
};
