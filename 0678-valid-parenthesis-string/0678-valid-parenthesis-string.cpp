class Solution {
public:
    bool checkValidString(string s) {
        //range using min and max BRUTE FORCE
        //O(n) TC and SC O (1)
        int mini = 0, maxi = 0;
        for(auto st : s){
            if(st == '(') {
                mini++;
                maxi++;
            }else if(st == ')'){
                mini = max(mini-1, 0);
                maxi--;
            }else {
                mini = max(mini-1, 0);
                maxi++;
            }
            //if(mini<0) mini=0; //directly can check the condition using max of mini value
            if(maxi<0) return false;
        }
        return (mini==0);
    }
};