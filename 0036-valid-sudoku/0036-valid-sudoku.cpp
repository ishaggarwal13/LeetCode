class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int count=9;
        int row[count][count] = {false};
        int col[count][count] = {false};
        int sub[count][count] = {false};

        for(int r=0; r<count; r++){
            for(int c=0; c<count; c++){
                if(board[r][c] == '.'){
                    continue;
                }

                int idx = board[r][c] - '0' - 1;
                int area = (r/3) * 3 + (c/3);

                if( row[r][idx] || col[c][idx] || sub[area][idx] ){
                    return false;
                }

                row[r][idx] = true;
                col[c][idx] = true;
                sub[area][idx] = true;
            }
        }
        return true;
    }
};