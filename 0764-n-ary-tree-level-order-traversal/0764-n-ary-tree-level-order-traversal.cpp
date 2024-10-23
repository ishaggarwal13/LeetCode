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
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int level = q.size();
            vector<int> currlevel;
            for(int i=0; i<level; i++){
                Node* curr = q.front();
                q.pop();
                currlevel.push_back(curr->val);

                for(auto it : curr->children){
                    q.push(it);
                }
            }
            ans.push_back(currlevel);
        }
        return ans;
    }
};