class Solution {
public:
    string boardToString(vector<vector<int>>& board)
    {
        string str = "";
        for(int i = 0; i<2; i++)
            for(int j = 0; j<3; j++)
                str+=to_string(board[i][j]);
            
        return str;
    }
    
    bool checkIsCorrect(string &s)
    {
        return s == "123450";
    }
    
    int slidingPuzzle(vector<vector<int>>& board) 
    {
        queue<pair<string, int>> boardQ;
        unordered_set<string> vis;
        vector<vector<int>> directions = {{1, 3}, {0, 2, 4}, {1, 5},
                                          {0, 4}, {1, 3, 5}, {2, 4}};
        
        string initString = boardToString(board);
        
        boardQ.push({initString, 0});
        vis.insert(initString);

        while(!boardQ.empty())
        {
            string temp = boardQ.front().first;
            int moves = boardQ.front().second;
            boardQ.pop();
            
            if(checkIsCorrect(temp)) return moves;
            int zeroPos = temp.find('0');
            
            for(auto swaps : directions[zeroPos])
            {
                string nextTemp = temp;
                swap(nextTemp[swaps], nextTemp[zeroPos]);
                if(vis.find(nextTemp) == vis.end())
                {
                    vis.insert(nextTemp);
                    boardQ.push({nextTemp, moves+1});
                }
            }
        }
        
        return -1;
    }
};