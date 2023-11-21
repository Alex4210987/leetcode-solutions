class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            inDegree[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            cnt++;
            for (auto& next : graph[cur]) {
                inDegree[next]--;
                if (inDegree[next] == 0)
                    q.push(next);
            }
        }
        return cnt == numCourses;
    }
};
