class Solution {
public:
    //O(n) and O(1)
    int minAddToMakeValid(string s) {
        int count = 0;
        int ans = 0;
        for(char str: s){
            if(str == '('){
                count++;
            } else {
                (count > 0) ? count-- : ans++;
            }
        }
        return (ans + count);
    }
};