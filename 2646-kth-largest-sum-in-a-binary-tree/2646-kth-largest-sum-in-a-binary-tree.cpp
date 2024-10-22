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
    static void f(TreeNode* root, int level, long long* sum, int& sz){
        if (sz<=level) sz++;
        sum[level]+=root->val;
        if (root->left) f(root->left, level+1, sum, sz);
        if (root->right) f(root->right, level+1, sum, sz);
    }
    static long long kthLargestLevelSum(TreeNode* root, int k) {
        // declare the res vector to store the sum on each level
        // decalre the queue to start bfs
        // in bfs use level to find the sum at each level and store them in res
        // check the base condition is k > res.size()
        // sort the res in desec order to find the kth largest sum
        // return res[k-1]
        long long sum[100000]={0};
        int sz=0;
        f(root, 0, sum, sz);
        if (sz<k) return -1;
        nth_element(sum, sum+(k-1), end(sum), greater<>());
        return sum[k-1];
    }
};