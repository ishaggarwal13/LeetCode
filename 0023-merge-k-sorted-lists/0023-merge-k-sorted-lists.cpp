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
    ListNode* mergeTwoSorted(ListNode *l1, ListNode* l2)
    {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
       
        if(l1->val <= l2->val) {
            l1->next = mergeTwoSorted(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoSorted(l1, l2->next);
            return l2;
        }
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        int len = lists.size();
        if(len == 0) return NULL;

        while(len>1){
            for(int i=0; i<len/2; i++){
                lists[i] = mergeTwoSorted(lists[i], lists[len-i-1]);
            }
            len = (len+1)/2;
        }
        return lists.front();
    }
    
};