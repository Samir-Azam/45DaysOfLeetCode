class Solution {
private:
    void dfs(int curr, vector<vector<int>>&adjList, vector<bool>&visited){
        visited[curr] = true;
        for (auto ele:adjList[curr]){
            if (!visited[ele]){
                dfs(ele, adjList, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>>adjList(n);
        

        for (int i=0;i<n;i++ ){
            for (int j=0;j<n;j++){
                if (i!=j && isConnected[i][j]==1){
                    adjList[i].push_back(j);
                }
            }
        }

        vector<bool>visited(n, false);
        int count = 0;
        for (int i=0;i<n;i++){
            if (!visited[i]){
                count++;
                dfs(i, adjList, visited);
            }
        }

        return count;
    }
};