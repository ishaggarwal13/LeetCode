class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        unordered_set<int> s1, s2;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(s1.find(matrix[i][j]) != s1.end()){ //column (0,0), (0,1), ...
                   return false; //same element exsit already
                } else {
                     s1.insert(matrix[i][j]);
                }

                if(s2.find(matrix[j][i]) != s2.end()){ //row (0,0), (1,0), ...
                   return false; //same element exsit already
                } else {
                     s2.insert(matrix[j][i]);
                }
            }
            s1.clear();
            s2.clear();    
        }
        return true;
    }
};