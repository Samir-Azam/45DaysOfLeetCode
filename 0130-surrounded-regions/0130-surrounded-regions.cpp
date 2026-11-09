class Solution {
private:
    void dfs(int cr, int cc, int m, int n, vector<pair<int, int>>&directions,  vector<vector<char>>&board){
        board[cr][cc] = '$';
        for (auto it: directions){
            int nr = cr+it.first;
            int nc = cc+it.second;
            if (nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O'){
                dfs(nr, nc, m, n, directions, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        vector<pair<int, int>>temp;
        int m = board.size();
        int n = board[0].size();
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if ((i==0) || (j==0) || (i==m-1) || (j==n-1) && (board[i][j]=='O')){
                    temp.push_back({i,j});
                }
            }
        }

        vector<pair<int, int>>directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto it: temp){
            int cr = it.first;
            int cc = it.second;
            if (board[cr][cc]=='O') dfs(cr, cc, m, n, directions, board);
        }

        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (board[i][j]=='O') board[i][j]='X';
                else if (board[i][j]=='$') board[i][j]='O';
            }
        }
    }
};