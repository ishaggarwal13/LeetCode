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
#include <execution>
pair<TreeNode*, int> que[100005];
int ft, rr;
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        ft=rr=0;
        que[rr++]={root, root->val};
        int dep=0;
        while(rr-ft){
            int sz=rr-ft;
            int st=ft;
            int sum=0;
            while(sz--){
                auto front = que[ft++];
                TreeNode* now = front.first;
                sum+=now->val;
                int child_sum = 0;
                if(now->left)child_sum += now->left->val;
                if(now->right)child_sum += now->right->val;
                if(now->left)que[rr++]={now->left, child_sum};
                if(now->right)que[rr++]={now->right, child_sum};
            }
            for(;st<ft;st++)
                que[st].first->val = sum - que[st].second;
        }

        return root;
    }
};