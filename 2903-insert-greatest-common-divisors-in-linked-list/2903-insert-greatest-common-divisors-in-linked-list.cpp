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
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* curr = head;
        ListNode* node = head->next;
        
        while(node){
            int gcd_val = gcd(curr->val, node->val);

            ListNode* newNode = new ListNode(gcd_val);

            curr->next = newNode;
            newNode->next = node;

            curr = node;
            node = node->next;
        }

        return head;
    }
};