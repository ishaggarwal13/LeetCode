/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //O(n) & O(n)
        //using hash table to store the visised nodes 
        
        unordered_set<ListNode*> visNodes;
        ListNode* curr = head;

        while(curr){
            if(visNodes.find(curr) != visNodes.end()){
                return true;
            }
            visNodes.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};