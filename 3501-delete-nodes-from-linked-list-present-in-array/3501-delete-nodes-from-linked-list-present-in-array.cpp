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
        unordered_set<int> NUMS(nums.begin(), nums.end());
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            if(NUMS.find(curr->val) != NUMS.end()){
                if(prev) prev->next = curr->next; //skip node which is present in array
                else head = curr->next; //if prev is null means curr is at head
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }  
};