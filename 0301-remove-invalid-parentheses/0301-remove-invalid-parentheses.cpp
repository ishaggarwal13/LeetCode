class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        //solving with bfs as need to do minimum number of invalid
        vector<string> res;
        queue<string> q;
        unordered_set<string> vis;

        q.push(s);
        vis.insert(s);
        bool found = false;

        while(!q.empty()){
            string curr = q.front();
            q.pop();

            if(isValid(curr)){
                res.push_back(curr);
                found = true;
            }

            if(found) continue;

            for(int i=0; i<curr.length(); i++){
                if(curr[i] != '(' && curr[i] != ')') continue;
                string nextState = curr.substr(0, i) + curr.substr(i + 1);

                if(vis.find(nextState) == vis.end()){
                    vis.insert(nextState);
                    q.push(nextState);
                }
            }
        }
        return res;
    }
private:
    bool isValid(const string& s){
        int count = 0;
        for(char c: s){
            if(c == '(') count++;
            if(c == ')'){
                if(count == 0) return false;
                count--;
            }
        }
        return count == 0;
    }
};