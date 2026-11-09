class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        // same as distance of nearest 1 , land - 0 , water - 1
        int m = isWater.size();
        int n = isWater[0].size();

        queue<pair<int, int>>q; // for storing indexes 
        vector<vector<int>>ans(m, vector<int>(n, 0));
        vector<vector<int>>visited(m, vector<int>(n, 0));
        int countZeros = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (isWater[i][j]==1){
                    visited[i][j]=1;
                    q.push({i, j});
                }else{
                    countZeros++;
                }
            }
        }

        int dist = 1;
        vector<pair<int, int>>directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        while(!q.empty() && countZeros>0){
            int size = q.size();
            for (int i=0;i<size;i++){
                int cr = q.front().first;
                int cc = q.front().second;
                q.pop();
                for (auto dir: directions){
                    int nr = cr + dir.first;
                    int nc = cc + dir.second;
                    if (nr>=0 && nr<m && nc>=0 && nc<n && isWater[nr][nc]==0 && visited[nr][nc]==0){
                        visited[nr][nc]=1;
                        q.push({nr, nc});
                        ans[nr][nc]=dist;
                        countZeros--;
                    }
                }
            }
            dist++;

        }

        return ans;

    }
};