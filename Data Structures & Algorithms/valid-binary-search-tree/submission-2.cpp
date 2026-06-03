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
    bool help(TreeNode* root, int upper, int lower){
        if (root == nullptr) return true;
        if (root->val <= lower || root->val >= upper) return false;
        return help(root->left, root->val, lower) && help(root->right, upper, root->val);
    }

    bool isValidBST(TreeNode* root) {
        return help(root, INT_MAX, INT_MIN);
    }
};
