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
        // Base case: if left is 1, we start reversing from here
        if (left == 1) {
            return reverseFirstN(head, right);
        }
        
        //move towards the left position
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }

private:
    ListNode* reverseFirstN(ListNode* head, int n) {
        // Base case: if n == 1, we stop
        if (n == 1) {
            return head;
        }

        // Recursively reverse the next `n-1` nodes
        ListNode* newHead = reverseFirstN(head->next, n - 1);

        // Reversing the current pair of nodes

        ListNode* nextNode = head->next; //nextNode is the node that will be moved to the front.
        //Skip nextNode in the original list and link head to the node after nextNode. 
        //This detaches nextNode.
        head->next = nextNode->next;
        nextNode->next = head; //Place nextNode before head to reverse their order.

        // Return the new head of the reversed list
        return newHead;
    }
};