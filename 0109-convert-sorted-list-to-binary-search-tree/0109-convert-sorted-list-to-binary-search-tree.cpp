/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    //O(nlogn) & O(1)
    TreeNode* convert(ListNode* start, ListNode* end){
        if(start == end) return nullptr;

        ListNode* slow = start;
        ListNode* fast = start;

        while(fast != end && fast->next != end){
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val); //slow is the mid of teh list
        root->left = convert(start, slow);
        root->right = convert(slow->next, end);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        return convert(head, nullptr); //start and end
    }
};