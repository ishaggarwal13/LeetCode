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
        
        Node* level = root;

        while(level){
            Node* curr = level;
            Node* dummy = new Node(0);
            Node* prev = dummy;

            while(curr){
                if(curr->left != nullptr){
                    prev->next = curr->left; //set left node to prev
                    prev = prev->next; //move prev pointer
                }
                if(curr->right != nullptr){
                    prev->next = curr->right; //set prev node next to curr right node
                    prev = prev->next;
                }
                curr = curr->next;
            }
            level = dummy->next; //set to next level
            delete dummy; //free dummy space;
        }
        return root;
    }
};