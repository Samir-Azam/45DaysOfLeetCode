class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0]==1) return -1;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int,pair<int,int>>>,greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>>visited(m, vector<int>(n,0));

        pq.push({1, {0, 0}});
        visited[0][0]=1;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int row = curr.second.first;
            int col = curr.second.second;
            int length = curr.first;

            if (row==m-1 && col==n-1) return length;

            for (int i=-1;i<=1;i++){
                for (int j=-1;j<=1;j++){
                    int nr = row+i;
                    int nc = col+j;
                    if (nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] && grid[nr][nc]==0){
                        visited[nr][nc]=1;
                        pq.push({length+1, {nr, nc}});
                    }
                }
            }

        }
        return -1;
    }
};