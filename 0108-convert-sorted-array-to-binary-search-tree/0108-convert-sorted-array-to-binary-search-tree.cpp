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
    TreeNode* arraySorted(vector<int>& nums, int start, int end){
        if(start<=end){
            int mid = start + (end-start)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = arraySorted(nums, start, mid-1);
            root->right = arraySorted(nums, mid+1, end);
            return root;
        }
        return nullptr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return arraySorted(nums, 0, nums.size()-1);
    }
};