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
    unordered_map<int, pair<int, int>> mp;
    unordered_map<int, vector<pair<int, int>>> mp2;

    int height(TreeNode* root, int level = 0) 
    {
        if (!root)
            return 0;
        if (mp.find(root->val) != mp.end())
            return mp[root->val].first;

        int l = height(root->left, level + 1);
        int r = height(root->right, level + 1);
        int curr = 1 + max(l, r);

        mp[root->val] = {curr, level};

        mp2[level].push_back({root->val, curr});

        return curr;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        int H = height(root) - 1;
        int m = queries.size();

        vector<int> ans(m, H);
        for (int i = 0; i < m; i++)
        {
            int q = queries[i];
            int lev = mp[q].second;
            int maxi = 0;
            int secondMaxi = 0;
            for (auto a : mp2[lev]) 
            {
                if (a.second > maxi) 
                {
                    secondMaxi = maxi;
                    maxi = a.second;
                } 
                else if (a.second > secondMaxi) 
                {
                    secondMaxi = a.second;
                }
            }

            if (maxi == mp[q].first) ans[i] = H - maxi + secondMaxi;
        }

        return ans;
    }
};