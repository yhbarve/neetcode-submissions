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
    ListNode* mergeLists(ListNode* l1, ListNode* l2){
        ListNode* sol = new ListNode(0);
        ListNode* head = sol;
        while (l1 && l2){
            if (l1->val <= l2->val){
                ListNode* newNode = new ListNode(l1->val);
                head->next = newNode;
                head = head->next;
                l1 = l1->next;
            } else {
                ListNode* newNode = new ListNode(l2->val);
                head->next = newNode;
                head = head->next;
                l2 = l2->next;
            }
        }

        while (l1){
            ListNode* newNode = new ListNode(l1->val);
            head->next = newNode;
            head = head->next;
            l1 = l1->next;
        }

        while (l2){
            ListNode* newNode = new ListNode(l2->val);
            head->next = newNode;
            head = head->next;
            l2 = l2->next;
        }

        return sol->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        while (lists.size() > 1){
            ListNode* l1 = lists.back();
            lists.pop_back();
            ListNode* l2 = lists.back();
            lists.pop_back();
            ListNode* mergedList = mergeLists(l1, l2);
            lists.insert(lists.begin(), mergedList);
        }

        if (lists.size() == 1) return lists.back();
        return nullptr;
    }
};
