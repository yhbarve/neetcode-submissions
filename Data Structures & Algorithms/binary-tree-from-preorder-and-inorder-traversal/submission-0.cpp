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
    TreeNode* dfs(vector<int> preorder, vector<int> inorder){
        if (preorder.size() == 0) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        if (preorder.size() == 1) return root;

        vector<int> leftPreorder;
        vector<int> leftInorder;
        vector<int> rightPreorder;
        vector<int> rightInorder;
        for (auto i : inorder){
            if (i != root->val) leftInorder.push_back(i);
            else break;
        }
        for (int i = leftInorder.size()+1; i < inorder.size(); i++){
            rightInorder.push_back(inorder[i]);
            rightPreorder.push_back(preorder[i]);
        }
        for (int i = 1; i <= leftInorder.size(); i++){
            leftPreorder.push_back(preorder[i]);
        }
        root->left = dfs(leftPreorder, leftInorder);
        root->right = dfs(rightPreorder, rightInorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, inorder);
    }
};
