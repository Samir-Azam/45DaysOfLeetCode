class Solution {
public:
    bool bfs(int node, vector<int>&visited, vector<vector<int>>& graph){
        queue<pair<int, int>>q;
        q.push({node, 0});
        visited[node]=0;
        while(!q.empty()){
            int curr = q.front().first;
            int color = q.front().second;
            q.pop();
            for (auto adjacent: graph[curr]){
                if (visited[adjacent]==-1){
                    visited[adjacent] = !color;
                    q.push({adjacent, !color});
                }else{
                    // already visited
                    if (color==visited[adjacent]) return false;
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n, -1);

        for (int i=0;i<n;i++){
            if (visited[i]==-1){
                if (bfs(i, visited, graph)==false) return false;
            }
        }

        return true;
    }
};