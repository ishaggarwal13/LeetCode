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
    TreeNode* replaceValueInTree(TreeNode* root) {
        // set root value to 0 as there is no sbiling nodes to root
        root->val = 0;
        // start bfs or dfs anything to find the sum of level
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int level = q.size();
            int sum = 0;
            vector<TreeNode*> buff;

            for(int i=0; i<level; i++){
                TreeNode* curr = q.front();
                q.pop();
                buff.push_back(curr);

                if(curr->left) {
                    q.push(curr->left);
                    sum += curr->left->val;
                }

                if(curr->right) {
                    q.push(curr->right);
                    sum += curr->right->val;
                }
            }

            for(auto node : buff){
                int t = sum;
                if(node->left) t -= node->left->val;
                if(node->right) t -= node->right->val;
                if(node->left) node->left->val = t;
                if(node->right) node->right->val = t;
            }
        }
        return root;
    }
};