class Solution {
public:
    //o(d), o(d)
    bool isPalindrome(int x) {
        string s = to_string(x);
        //two pointers
        int i = 0;
        int j = s.size()-1;

        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};