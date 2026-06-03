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
    void getNodes(TreeNode* root, vector<int>& pq){
        if (root == nullptr) return;
        getNodes(root->left, pq);
        pq.push_back(root->val);
        getNodes(root->right, pq);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> pq;
        getNodes(root, pq);
        return pq[k-1];
    }
};
