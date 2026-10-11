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
        // int i = 0;
        // int j = s.size()-1;
        // while(i<j){
        //     swap(s[i++], s[j--]);
        // }

        //recursion
        reverse(0, s.size()-1, s);

        //stl
        // reverse(s.begin(), s.end());
    }

    void reverse(int i, int j, vector<char>& s){
        if(i>=j) return; //base case
        swap(s[i], s[j]);
        reverse(i+1, j-1, s);
    }
};