class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        vector<vector<char>> ret(box[0].size());
        for(int i = ret.size();i--;)
        {
            ret[i].resize(box.size());
            for(int j = box.size(); j--;)
                ret[i][j]='.';
        }
        int col = box.size();
        for(auto &row:box)
        {
            col--;
            // calc each row
            int free = row.size()-1;
            for(int i = row.size(); i--;)
            {
                switch(row[i])
                {
                    case '*':
                        ret[i][col] = '*';
                        free = i-1;
                        break;
                    case '#':
                        ret[free][col] = '#';
                        free--;
                        break;
                    default:
                }
            }
        }
        return ret;
    }
};