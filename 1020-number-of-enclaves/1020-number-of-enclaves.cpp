class Solution {
private:
    void dfs(int row, int col, int m, int n, vector<pair<int, int>>& direction, vector<vector<int>>& grid, vector<vector<int>>& visited){
        visited[row][col]=1;
        for (auto it: direction){
            int nr = row+it.first;
            int nc = col+it.second;

            if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && !visited[nr][nc]){
                dfs(nr, nc, m, n, direction, grid, visited);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>>visited(m, vector<int>(n, 0));
        vector<pair<int, int>>boundary_index;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if ((i==0 || j==0 || i==m-1 || j==n-1) && (grid[i][j]==1)){
                    boundary_index.push_back({i, j});
                }
            }
        }
        vector<pair<int, int>>dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto it: boundary_index){
            int row = it.first;
            int col = it.second;

            if (!visited[row][col]) dfs(row, col, m, n, dir, grid, visited);
        }
        
        int count = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j]==1 && !visited[i][j]) count++;
            }
        }
        return count;
    }
};