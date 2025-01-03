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
    TreeNode* invertTree(TreeNode* root) {
        //mirror tree - BFS FOR O(N) & O(N)
        if(root == NULL) return NULL;

        queue<TreeNode*> s;
        s.push(root);

        while(!s.empty()){
            TreeNode* curr = s.front();
            s.pop();

            swap(curr->left, curr->right);

            if(curr->left) s.push(curr->left);
            if(curr->right) s.push(curr->right);
        }

        return root;
    }
};