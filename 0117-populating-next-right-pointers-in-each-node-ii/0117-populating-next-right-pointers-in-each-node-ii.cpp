/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        //using queue as tree is not a perfect binary tree so q, will be helpfull to maintain nodes at each level
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int level = q.size();
            Node* prev = nullptr; //for every new level prev set to null

            for(int i=0; i<level; i++){
                Node* node = q.front();
                q.pop();

                if(prev) {
                    prev->next = node;
                }
                prev = node;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            //set last node to null
            if(prev) prev->next = nullptr;
        }

        return root;
    }
};