class Solution {
public:
    void reverseString(vector<char>& s) {
        //stl
        reverse(s.begin(), s.end());

        //two pointers
        // int i = 0;
        // int j = s.size()-1;

        // while(i<j){
        //     char temp = s[i];
        //     s[i] = s[j];
        //     s[j] = temp;

        //     i++;
        //     j--;
        // }
    }
};