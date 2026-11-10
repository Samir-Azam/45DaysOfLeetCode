
class Solution {
private:
    bool dfs(int node, vector<int>& visited,
             vector<int>& path, vector<vector<int>>& adj) {

        visited[node] = 1;
        path[node] = 1;

        for (auto it : adj[node]) {

            if (!visited[it]) {
                if (dfs(it, visited, path, adj))
                    return true;
            }
            else if (path[it]) {
                return true;
            }
        }

        path[node] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {
                    if (prerequisites.size()==0) return true;
        vector<vector<int>> adj(numCourses);

        // Build directed graph
        int m = prerequisites.size();
        int n = prerequisites[0].size();
        for (int i=0;i<m;i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<int> visited(numCourses, 0);
        vector<int> path(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, path, adj))
                    return false;
            }
        }

        return true;
    }
};
