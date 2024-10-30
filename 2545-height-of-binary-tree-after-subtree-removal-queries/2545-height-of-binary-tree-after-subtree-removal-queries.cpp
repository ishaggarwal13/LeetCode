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
    int height[100001];
    int level[100001];
    int levelMaxHt[100001];
    int levelSecondMax[100001];

    int findHeight(TreeNode* root,int lvl){
        if(root == NULL) return 0;
        level[root->val] = lvl;
        int left = findHeight(root->left,lvl+1);
        int right = findHeight(root->right,lvl+1);
        height[root->val] = 1 + max(left,right);

        if(levelMaxHt[lvl] < height[root->val]){
            levelSecondMax[lvl] = levelMaxHt[lvl];
            levelMaxHt[lvl] = height[root->val];
        }
        else if(levelSecondMax[lvl] < height[root->val]){
            levelSecondMax[lvl] = height[root->val];
        }
        return height[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        findHeight(root,0);
        vector<int> result;
        for(auto& node : queries){
            int l = level[node];
            int level_max_ht = levelMaxHt[l];
            int h = height[node];
            int ans = l +(level_max_ht == h ? levelSecondMax[l] : levelMaxHt[l]) - 1;
            result.push_back(ans);
        }
        return result;
    }
};
/*
1. jis node ko delete krna h vo kis level pr h or uski kitni height h aur uss level ki max height aur second max height kya h.
2. agar jis node ko delete kr rahe ho aur ussi ki uss level pr max height h toh second max height nikalo .
3. formula = (node jis level pr h) + (height of other nodes on that level) -1

har ek node ki height aur level chahiye toh precompute it.and har levelki max height and second max height 
*/