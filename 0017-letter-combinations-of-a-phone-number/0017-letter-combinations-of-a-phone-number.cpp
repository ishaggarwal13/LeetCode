class Solution {
public:
    void backtrack(string& digits, int index, string curr, vector<string>& ans, vector<string>& mapping){
        if(index == digits.length()){
            ans.push_back(curr);
            return;
        }

        string letters = mapping[digits[index] - '0'];
        for(char letter : letters){
            backtrack(digits, index+1, curr + letter, ans, mapping);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<string> mapping = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        backtrack(digits, 0, "", ans, mapping);

        return ans;
    }
};