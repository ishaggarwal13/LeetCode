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
    //inorder
    void inorder(TreeNode* root, int& ans, int sum){
        if(!root) return;
        //check for leaf node
        if(root->left == NULL && root->right == NULL){
            sum = sum*10 + root->val;
            ans += sum;
            sum /= 10;
        }
        sum = sum*10 + root->val;
        inorder(root->left, ans, sum);
        inorder(root->right, ans, sum);
        sum = sum/10; //for backtrack reduce the last element
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        inorder(root, ans, 0);
        return ans;
    }
};