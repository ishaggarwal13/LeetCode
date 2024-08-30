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
    //recursive O(N) & O(H)~O(N)
    int dfs(TreeNode* root, int currsum){
        if(!root) return 0;
        currsum = currsum*10 + root->val; //storing value of root

        //checking for leaf node and return the currsum
        if(!root->left && !root->right) return currsum;

        int leftsum = dfs(root->left, currsum);
        int rightsum = dfs(root->right, currsum);

        return leftsum + rightsum;
    }
    
    int sumNumbers(TreeNode* root) {
        int currsum = 0;
        return dfs(root, currsum);
    }
};