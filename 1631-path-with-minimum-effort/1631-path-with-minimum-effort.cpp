class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // very easy question just apply dijkstra and question will be solved easily
        // approach 
        // 1. i will a pq to store absolute differences (efforts) in a sorted order the first end index that will be processed with an effort is going to be answer becuase we will use a min-heap

        int row = heights.size();
        int col = heights[0].size();
        
        // let's use set for easier implementation
        set<pair<int, pair<int, int>>>st;
        vector<pair<int, int>>directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>>visited(row, vector<int>(col, 0));
        // starting from top left
        st.insert({0, {0, 0}});
        while(!st.empty()){
            auto it = *(st.begin());
            st.erase(it);
            int effort = it.first;
            int row_number = it.second.first;
            int col_number = it.second.second;
            if (visited[row_number][col_number]) continue;
            visited[row_number][col_number]=1;
            int val = heights[row_number][col_number];
            if (row_number==row-1 && col_number==col-1) return effort;
            for (auto dir: directions){
                int nr = row_number + dir.first;
                int nc = col_number + dir.second;

                if (nr>=0 && nr<row && nc>=0 && nc<col && !visited[nr][nc]){
                    int new_effort = max(effort, abs(heights[nr][nc]-val));
                    st.insert({new_effort, {nr, nc}});
                }
            }
        }
        return -1;
    }
};