/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public: //RECURSIVE O(N) WITH O(N) SPACE(FUNCTION CALL STACK)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
    void helper(TreeNode* root, vector<int>& ans) {
        if(!root) return;
        helper(root->left, ans);
        helper(root->right, ans);
        ans.push_back(root->val);
    }
};