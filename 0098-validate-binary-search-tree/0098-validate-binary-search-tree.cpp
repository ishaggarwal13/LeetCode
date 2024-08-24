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
public: //O(n) & O(1)
    bool check(TreeNode* root, int* min, int* max){
        if(root == nullptr) return true; //empty node is bst

        if((min && root->val <= *min) || (max && root->val >= *max)){
            return false;
        }

        return check(root->left, min, &(root->val)) 
            && check(root->right, &(root->val), max);
    }
    bool isValidBST(TreeNode* root) {
        return check(root, NULL, NULL); //failed for INT_MAX AND MIN SOR USE NULL POINTERS
    }
};