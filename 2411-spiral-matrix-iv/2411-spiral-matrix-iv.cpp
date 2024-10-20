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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> nums(m,vector<int>(n,-1));
        ListNode* ptr = head;
        int i=0,j=0, endcol=n-1, endrow=m-1, startrow=1, startcol=0;
        int dir = 0;
        while(ptr){
            nums[i][j] = ptr->val;
            ptr = ptr->next;
            if(dir==0){
                if(j==endcol){
                    dir=1;
                    i++;
                    endcol--;
                }else j++;
            }
            else if(dir==1){
                if(i==endrow){
                    dir=2;
                    j--;
                    endrow--;
                }else i++;
            }
            else if(dir==2){
                if(j==startcol){
                    dir=3;
                    i--;
                    startcol++;
                }else j--;
            }
            else{
                if(i==startrow){
                    dir=0;
                    j++;
                    startrow++;
                }else i--;
            }
        }

        return nums;
    }
};