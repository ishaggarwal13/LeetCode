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
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        bitset<100001> bs;
        for(const int & i : nums){
            bs.set(i);
        }
        
        head = new ListNode(-1,head);
        ListNode * prev = head;
        while(head->next){
            if(bs[head->next->val]){
                head->next = head->next->next;
            }else{
                head = head->next;
            }
        }
        return prev->next;
    }  
};