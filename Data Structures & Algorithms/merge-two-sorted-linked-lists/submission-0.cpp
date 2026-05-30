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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merge = new ListNode();
        ListNode* mergeHead = merge;
        while (list1 != nullptr && list2 != nullptr){
            if (list1->val >= list2->val){
                ListNode* temp2 = list2->next;
                merge->next = list2;
                merge = list2;
                list2 = temp2;
            } else {
                ListNode* temp1 = list1->next;
                merge->next = list1;
                merge = list1;
                list1 = temp1;
            }
        }

        while (list1 != nullptr){
            ListNode* temp1 = list1->next;
            merge->next = list1;
            merge = list1;
            list1 = temp1;
        }

        while (list2 != nullptr){
            ListNode* temp2 = list2->next;
            merge->next = list2;
            merge = list2;
            list2 = temp2;
        }

        return mergeHead->next;
    }
};
