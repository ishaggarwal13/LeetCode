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
    ListNode* node;
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == 1){
            if(left == right){
                node = head->next;
                return head;
            }
            //reversing the list
            ListNode* nextNode = reverseBetween(head->next, left, right-1);
            head->next->next = head;
            head->next = node;
            return nextNode;
        }
         
        //till when we get the left = 1 which means it will start from left
        head->next = reverseBetween(head->next, left-1, right-1);
        return head;
    }
};