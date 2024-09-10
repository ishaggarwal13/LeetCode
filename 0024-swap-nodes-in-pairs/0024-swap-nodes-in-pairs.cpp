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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head;
        ListNode* prev = dummy;

        while(curr && curr->next){
            ListNode* first = curr;
            ListNode* second = curr->next;

            prev->next = second;
            first->next = second->next;
            second->next = first;

            prev = curr;
            curr = curr->next;
        }
        return dummy->next;

    }
};