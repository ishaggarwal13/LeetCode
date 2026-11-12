class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // To roatet a matrix by 90 degree there are two ways
        // first is transpose + reverse or vice versa
        // second is we can do the four end swaps roatation from ends
        int m = matrix.size();

        //transpose : swaps row with columns 
        for(int i=0; i<m; i++){
            for(int j=i+1; j<m; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        //reverse 
        for(int i=0; i<m; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};