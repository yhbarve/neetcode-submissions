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
    ListNode* reverseList(ListNode* head){
        ListNode* revHead = nullptr;
        while (head != nullptr){
            ListNode* temp = head->next;
            head->next = revHead;
            revHead = head;
            head = temp;
        }
        return revHead;
    }

    ListNode* mergeLists(ListNode* list1, ListNode* list2){
        ListNode* sol = new ListNode();
        ListNode* solHead = sol;
        while (list1 != nullptr && list2 != nullptr){
            cout << "Hi!" << endl;
            ListNode* temp1 = list1->next;
            ListNode* temp2 = list2->next;
            sol->next = list1;
            sol = list1;
            list1 = temp1;
            sol->next = list2;
            sol = list2;
            list2 = temp2;
        }

        while (list1 != nullptr){
            cout << "hi" << endl;
            ListNode* temp1 = list1->next;
            sol->next = list1;
            sol = list1;
            list1 = temp1;
        }

        return solHead;
    }

    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        cout << slow->val << endl;


        ListNode* rev = reverseList(slow->next);
        slow->next = nullptr;
        head = mergeLists(head, rev);
    }
};
