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
    ListNode* insertionSortList(ListNode* head) {
        //O(N^2) & O(1)
        if(!head) return head;

        ListNode* dummy = new ListNode(0); //to create sorted list
        ListNode* curr = head;
        while(curr){
            ListNode* prev = dummy;
            ListNode* next = curr->next; //storing next node to traverse the list
            while(prev->next && prev->next->val < curr->val){
                prev = prev->next;
            }
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }
        return dummy->next;
    }
};