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
    vector<vector<int>> res;
    void solve(TreeNode *root,int targetSum,int sum,vector<int> &vec)
    {
        if(!root)
            return;
        sum+=root->val;
        if(!root->left && !root->right)
        {
            if(sum==targetSum)
            {
                vec.push_back(root->val);
                
                res.push_back(vec);
                vec.pop_back() ;
            }
            return;
        }
        vec.push_back(root->val);
        solve(root->left,targetSum,sum,vec);
        solve(root->right,targetSum,sum,vec);
        vec.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int> vec ;
        solve(root,targetSum,sum,vec);
        return res;
    }
};