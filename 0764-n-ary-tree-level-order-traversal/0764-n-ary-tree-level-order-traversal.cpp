/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return ans;
        dfs(root, 0); // pass 0 level 
        return ans;
    }

    void dfs(Node* root, int level){
        if(!root) return;
        // check the level with ans.size()
        if(level == ans.size()){
            ans.emplace_back();
        }
        ans[level].emplace_back(root->val);

        for(auto it: root->children){
            dfs(it, level+1);
        }
    }
};