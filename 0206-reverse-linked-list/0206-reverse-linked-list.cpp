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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while(curr){
            ListNode* next = curr->next; //next points to next node from curr
            curr->next = prev; //now next pointer of 1->null which is prev
            prev = curr; //now prev points to 1 which later pointing null
            curr = next; //npw curr will point to next element to move forward
        }

        return prev;
    }
};