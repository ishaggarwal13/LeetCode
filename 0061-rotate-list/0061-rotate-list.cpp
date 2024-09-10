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
    ListNode* rotateRight(ListNode* head, int k) {
        //handle base case
        if(!head || !head->next || k==0) return head;
        //calculating n number of nodes
        ListNode* temp = head;
        int n = 1;
        while(temp->next){
            temp = temp->next;
            n++;
        }

        //no of rotations
        k = k%n;
        if(k==0) return head;

        //make circular list by connecting tail to head
        temp->next = head;

        //finding new tail by (n-k)
        temp = head;
        for(int i=1; i<n-k; i++){
            temp = temp->next;
        }

        //declare new head and disconnect the tail from newhead
        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};