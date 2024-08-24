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
    void dfs(TreeNode* root, int level, vector<int>& ans){ //reverse preorder
        if(root == nullptr) return;

        if(level == ans.size()) ans.push_back(root->val);

        dfs(root->right, level+1, ans);
        dfs(root->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        //if(root == nullptr) return {};

        // queue<TreeNode*> q;
        // q.push(root);
        vector<int> ans;

        // while(!q.empty()){
        //     int level = q.size();
        //     for(int i=0; i<level; i++){
        //         TreeNode* node = q.front();
        //         q.pop();
        //         if(i == (level-1)) ans.push_back(node->val);
        //         if(node->left) q.push(node->left);
        //         if(node->right) q.push(node->right);
        //     }
        // }
        // return ans;

        dfs(root, 0, ans);
        return ans;
    }
};