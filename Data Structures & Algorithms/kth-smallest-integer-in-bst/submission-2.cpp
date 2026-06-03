/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void getNodes(TreeNode* root, priority_queue<int>& pq, int k){
        if (root == nullptr) return;
        pq.push(root->val);
        if (pq.size() > k) pq.pop();
        getNodes(root->left, pq, k);
        getNodes(root->right, pq, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        getNodes(root, pq, k);
        return pq.top();
    }
};
