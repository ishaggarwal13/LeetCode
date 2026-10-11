class Solution {
public:
    void reverseString(vector<char>& s) {
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

        //swap function
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            swap(s[i++], s[j--]);
        }

        //recursion
        // reverse()

        //stl
        // reverse(s.begin(), s.end());

        
    }
};