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
        if(head == nullptr) return head;
        ListNode* curr = head;
        
        while(curr && curr->next){
            ListNode* node = curr->next;
            int gcd_val = gcd(curr->val, node->val);

            ListNode* newNode = new ListNode(gcd_val);
            curr->next = newNode;
            newNode->next = node;

            curr = node;
        }

        return head;
    }
};