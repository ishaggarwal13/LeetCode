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
    vector<int> preorder(Node* root) {
        // For N-ary tree we don't have two nodes to every root we have multiple child nodes
        // For multiple child nodes we need to call the recursie call for each child

        // for preorder we have RLR
        // now we will push root to the array and check for the root is null or not return empty vector
        // now using for loop we will traverse through the each child of the node and add into the vector
        if(!root) return {};

        vector<int> ans;
        ans.push_back(root->val);

        for(int i=0; i<root->children.size(); i++){
            vector<int> v1 = preorder(root->children[i]);
            ans.insert(ans.end(), v1.begin(), v1.end());
        }
        return ans;
    }
};