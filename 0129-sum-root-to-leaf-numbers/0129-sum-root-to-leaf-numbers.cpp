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
    //iterative using bfs using queue O(N) & O(H)~O(N)
    int sumNumbers(TreeNode* root) {
        int totalsum = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            auto [root, currsum] = q.front();
            q.pop();

            currsum = currsum*10 + root->val;
            if(!root->left && !root->right) totalsum += currsum;

            if(root->left) q.push({root->left, currsum});
            if(root->right) q.push({root->right, currsum});
        }

        return totalsum;
    }
};