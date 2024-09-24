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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
       int length = 0;
        vector<ListNode*> ans;
        ListNode* temp = head;
        while(temp){
            length++;
            temp = temp -> next;
        }
        temp = head;
        int count = length/k;
        int rem = length%k;
        ans.push_back(temp);
        while(--k){
            ListNode* prev = temp;
            if(rem>0){
                for(int i = 0; i<count+1; i++){
                    if(temp){
                        prev = temp;
                        temp = temp -> next;
                    }
                }
                rem--;
            }
            else{
                for(int i = 0; i<count; i++){
                    if(temp){
                        prev = temp;
                        temp = temp -> next;
                    }
                }
            }
            //can optimize by using while(temp) only for making groups of nodes but will do that later sometime else cuz so much bored  
            //cout<< temp -> val;
            if(prev){
                prev -> next = NULL;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};