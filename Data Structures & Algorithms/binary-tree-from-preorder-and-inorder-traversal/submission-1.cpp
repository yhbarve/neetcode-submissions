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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /*
            preorder = root, left, right
            inorder = left, root, right
            1, 2, 3, 4 | 2, 1, 3, 4
        */
        if (preorder.size() == 0) return nullptr;
        if (preorder.size() == 1){
            TreeNode* node = new TreeNode(preorder[0]);
            return node;
        } else {
            // left subtree
            vector<int> preorderLeft;
            vector<int> inorderLeft;
            for (auto i : inorder){
                if (i != preorder[0]){
                    inorderLeft.push_back(i);
                } else {
                    break;
                }
            }
            for (int i = 0; i < inorderLeft.size(); i++){
                preorderLeft.push_back(preorder[1+i]);
            }
            TreeNode* leftTree = buildTree(preorderLeft, inorderLeft);

            // right subtree
            vector<int> preorderRight(preorder.begin() + 1 + preorderLeft.size(), preorder.end());
            vector<int> inorderRight(inorder.begin() + 1 + preorderLeft.size(), inorder.end());
            TreeNode* rightTree = buildTree(preorderRight, inorderRight);
            TreeNode* root = new TreeNode(preorder[0]);
            root->left = leftTree;
            root->right = rightTree;
            return root;
        }
    }
};
