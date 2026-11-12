class Solution {
private:
    bool isSafe(int curr, vector<int>&visited, vector<int>&path, vector<int>&ans, 
    vector<vector<int>>&graph )
    {
        visited[curr] = 1;
        path[curr] = 1;

        for (auto adj: graph[curr]){
            if (!visited[adj]){
                if (isSafe(adj, visited, path, ans, graph)==false) return false;
            }else{
                if (path[adj]) return false;
            }
        }
        ans.push_back(curr);
        path[curr]=0;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int nodes = graph.size();

        vector<int>visited(nodes, 0);
        vector<int>path(nodes, 0);

        for (int i=0;i<nodes;i++){
            if (!visited[i]){
                isSafe(i, visited, path, ans, graph);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};