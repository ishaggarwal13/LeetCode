class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<bool> ans;
        vector<vector<int>> graph(numCourses);
        vector<vector<bool>> table(numCourses, vector<bool>(numCourses, false));
        vector<int> inDegree(numCourses, 0);

        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            inDegree[prerequisites[i][1]]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) if(inDegree[i] == 0) q.push(i);

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto &it : graph[curr]){
                table[curr][it] = true;
                for(int i=0; i<numCourses; i++){
                    if(table[i][curr] == true) table[i][it] = true;
                }
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        for(int i=0; i<queries.size(); i++) ans.push_back(table[queries[i][0]][queries[i][1]]);
        return ans;
    }
};