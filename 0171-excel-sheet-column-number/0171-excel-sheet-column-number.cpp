class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        //extracting alphabet
        for(auto& c : columnTitle){
            int d = c - 'A' + 1; //number of char as A-1 B-2...
            res = 26*res + d; //multipy res by 26 and then add d
        }
        return res;
    }
};