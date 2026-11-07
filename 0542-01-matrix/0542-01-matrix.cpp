class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // try to expand from zero
        int rows = mat.size();
        int cols = mat[0].size();

        queue<pair<int, int>>q;
        vector<vector<int>>ans(rows, vector<int>(cols, 0));
        vector<vector<int>>visited(rows, vector<int>(cols, 0));
        

        int totalOnes = 0;
        for (int i=0;i<rows;i++){
            for (int j=0;j<cols;j++){
                if (mat[i][j]==0){
                    q.push({i, j});
                    visited[i][j]=1;
                }else totalOnes++;
            }   
        }

        // bfs
        int distance = 1;
        vector<pair<int, int>>directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!q.empty()){
            
            int size = q.size();

            for (int i=0;i<size;i++){
                int cr = q.front().first;
                int cc = q.front().second;
                q.pop();

                for (int i=0;i<4;i++){
                    int nr = cr+directions[i].first;
                    int nc = cc+directions[i].second;

                    if (nr>=0 && nc>=0 && nr<rows && nc<cols && !visited[nr][nc]){
                        if (mat[nr][nc]==1){
                            ans[nr][nc] = distance;
                            visited[nr][nc]=1;
                            q.push({nr, nc});
                            totalOnes--;
                        }
                    }
                }
                
            }
            if (totalOnes==0) break;
            distance++;
        }

        return ans;
    }
};