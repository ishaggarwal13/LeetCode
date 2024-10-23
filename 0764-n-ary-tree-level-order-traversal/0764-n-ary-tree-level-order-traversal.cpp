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
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> curr;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            Node* n = q.front();
            q.pop();
            if(n==NULL) {
                ans.push_back(curr);
                curr.clear();
                if(!q.empty()) {
                    q.push(NULL);
                }
            } else {
                curr.push_back(n->val);
                for(int i=0;i<n->children.size();i++) {
                    q.push(n->children[i]);
                }
            }
        }
        return ans;
    }
};