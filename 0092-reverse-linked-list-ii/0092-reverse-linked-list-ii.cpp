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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //base case
        if(!head || left == right) return head;

        //create dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        for(int i=1; i<left; i++){
            prev = prev->next; //move prev to one node before the left
        }

        ListNode* curr = prev->next;
        ListNode* next = nullptr; //for next node after finding left node
        
        for(int i=0; i<right-left; i++){
            next = curr->next; //next points to next node of curr
            curr->next = next->next; //detach next node from the list
            next->next = prev->next; //attach next node with curr node
            prev->next = next; //points prev next to next node
        }

        return dummy->next;
    }
};