class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            unordered_set<int> s1, s2;
            for(int j=0; j<n; j++){
                s1.insert(matrix[i][j]); //row
                s2.insert(matrix[j][i]); //column
            }
            if(s1.size() != n || s2.size() != n) return false;   
        }
        return true;
    }
};