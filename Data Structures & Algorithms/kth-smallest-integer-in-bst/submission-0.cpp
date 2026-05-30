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
    void inOrderTraversal(TreeNode* root, int k, vector<int>& elements){
        if (root == nullptr) return;
        inOrderTraversal(root->left, k, elements);
        elements.push_back(root->val);
        inOrderTraversal(root->right, k, elements);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> elements;
        inOrderTraversal(root, k, elements);
        int n = elements.size();
        return elements[k-1];
    }
};
