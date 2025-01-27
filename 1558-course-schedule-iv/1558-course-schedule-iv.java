class Solution {
    public List<Boolean> checkIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
        List<Boolean> ans = new ArrayList<>();
        List<List<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            graph.add(new ArrayList<>());
        }
        
        boolean[][] table = new boolean[numCourses][numCourses];
        int[] inDegree = new int[numCourses];

        for (int[] prerequisite : prerequisites) {
            graph.get(prerequisite[0]).add(prerequisite[1]);
            inDegree[prerequisite[1]]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.offer(i);
            }
        }

        while (!q.isEmpty()) {
            int curr = q.poll();
            for (int next : graph.get(curr)) {
                table[curr][next] = true;
                for (int i = 0; i < numCourses; i++) {
                    if (table[i][curr]) {
                        table[i][next] = true;
                    }
                }
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    q.offer(next);
                }
            }
        }

        for (int[] query : queries) {
            ans.add(table[query[0]][query[1]]);
        }
        return ans;

    }
}