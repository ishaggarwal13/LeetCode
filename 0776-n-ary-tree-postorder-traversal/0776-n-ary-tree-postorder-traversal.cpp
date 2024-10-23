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
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int> ans;
        stack<Node*> st;
        st.push(root);

        while(!st.empty()){
            Node* curr = st.top();
            st.pop();
            // Insert the value in the begin to reverse the vector
            ans.insert(ans.begin(), curr->val);

            for(auto it : curr->children){
                st.push(it);
            }
        }
        return ans;
    }
};