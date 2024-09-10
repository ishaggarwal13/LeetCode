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
            ListNode* prev = dummy; //prev points to dummy for every curr node
            ListNode* next = curr->next; //storing next node to traverse the list
            //traverse from dummy thorugh teh list to find the right spot
            while(prev->next && prev->next->val < curr->val){
                prev = prev->next;
            }
            //find sport now set curr->next suppose 3->, prev 2 and prev->next 4
            curr->next = prev->next;
            prev->next = curr; //prev = 2 prev->next 2->3->4
            curr = next; //curr points back to list
        }
        return dummy->next;
    }
};