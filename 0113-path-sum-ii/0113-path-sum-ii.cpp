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
    void dfs(TreeNode* root, int targetSum, vector<int>& currpath, vector<vector<int>>& res){
        if(!root) return;
        currpath.push_back(root->val); //add the value of node

        //check for leaf node and if path sums to targetsum
        if(!root->left && !root->right && targetSum == root->val){
            res.push_back(currpath);
        } else { //tarverse through left and right node
            dfs(root->left, targetSum - root->val, currpath, res);
            dfs(root->right, targetSum - root->val, currpath, res);
        }
        //backtrack remove the last element 
        currpath.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> currpath;
        dfs(root, targetSum, currpath, res);
        return res;
    }
};