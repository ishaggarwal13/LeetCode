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
        if(!root) return nullptr;
        connecting(root->left, root->right);
        return root;
    }
    void connecting(Node* left, Node* right){
        if(!left) return;

        left->next = right; //pointing left->next to right
        connecting(left->left, left->right); //left and right node of same left parent
        connecting(left->right, right->left); //left and right of diff node that bridge
        connecting(right->left, right->right); //left and right node of same right parent
    }
};