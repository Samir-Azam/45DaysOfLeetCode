class Solution {

private: 
    void dfs(int row, int col, vector<vector<int>>&visited, vector<vector<char>>&grid, vector<int>&delrow, vector<int>&delcol){
        visited[row][col]=1;
        for (int i=0;i<delrow.size();i++){
            int newr = row+delrow[i];
            int newc = col+delcol[i];
            if (newr>=0 && newr<grid.size() && newc>=0 && newc<grid[0].size() && !visited[newr][newc] && grid[newr][newc]=='1'){
                dfs(newr, newc, visited, grid, delrow, delcol);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>>visited(row, vector<int>(col, 0));

        vector<int> delrow = {-1, 0, 0, 1};
        vector<int> delcol = {0, -1, 1, 0};

        int count = 0;
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                if (grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    dfs(i, j, visited, grid, delrow, delcol);
                }
            }
        }
        return count;
    }
};