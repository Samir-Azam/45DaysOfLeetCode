class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // we can use dijkstra algorithm here 

        // here instead of distance we have effort 
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>>efforts(row, vector<int>(col, 1e9));
        vector<pair<int, int>>directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;

        pq.push({0, {0, 0}});
        efforts[0][0]=0;
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int effort = top.first;
            int ri = top.second.first;
            int ci = top.second.second;

            if (ri==row-1 && ci==col-1) return effort;

            for (auto dir: directions){
                int nr = ri+dir.first;
                int nc = ci+dir.second;

                if (nr>=0 && nr<row && nc>=0 && nc<col){
                    int new_effort = max(effort, abs(heights[nr][nc]-heights[ri][ci]));
                    if (new_effort<efforts[nr][nc]){
                        pq.push({new_effort, {nr, nc}});
                        efforts[nr][nc] = new_effort;
                    }
                }
            }

        }
        return -1;
    }
};