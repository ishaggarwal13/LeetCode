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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>numSet(nums.begin(), nums.end());

            ListNode* dummy = new ListNode(0);
            ListNode* current = dummy;

            while(head){
                if(numSet.find(head->val)==numSet.end()){
                    current->next = head;
                    current = current->next;

                }
                head = head->next;
            }  
            current->next = nullptr;
            return dummy->next;
        }  
};