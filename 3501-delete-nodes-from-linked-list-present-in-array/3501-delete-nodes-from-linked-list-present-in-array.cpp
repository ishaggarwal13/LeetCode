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
        std::bitset<100001> bs;
        for (int num : nums) {
            bs.set(num);
        }
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        ListNode* curr = head;
        while (curr) {
            ListNode* tmp = curr->next;
            if (bs[curr->val]) {
                prev->next = tmp;
            }
            else {
                prev = curr;
            }
            curr = tmp;
        }

        return dummy.next;
    }  
};