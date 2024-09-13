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
        if(!head || !head->next) return head;

        //newnode points to last node
        ListNode* newNode = reverseList(head->next); //head->next points to 5
        head->next->next = head; //head->next = 5, 5->next = 4
        head->next = nullptr;
        return newNode;
    }
};