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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL || root->val == val) {
            return root;
        }
        
        // If the target value is less than the root's value, search in the left subtree
        if (val < root->val) {
            return searchBST(root->left, val);
        } else {
            // If the target value is greater than the root's value, search in the right subtree
            return searchBST(root->right, val);
        }
    }
};