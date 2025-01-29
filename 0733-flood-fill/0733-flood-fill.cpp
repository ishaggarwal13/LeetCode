class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image, sr, sc, color);
        return image;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc, int color){
        if(image[sr][sc] == color) return; 
        int main = image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr, sc});

        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();

            int r = p.first;
            int c = p.second;

            if(r < 0 || r >= image.size() || c < 0 || c >= image[0].size() 
            || image[r][c] != main) {
                continue;
            }

            image[r][c] = color;
            q.push({r-1,c});
            q.push({r+1,c});
            q.push({r,c-1});
            q.push({r,c+1});
        }
    }
};