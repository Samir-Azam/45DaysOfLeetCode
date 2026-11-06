class Solution {
private: 
    bool isValid(int row, int col, vector<vector<int>>&image){
        int totalRow = image.size();
        int totalCol = image[0].size();

        if (row>=0 && row<totalRow && col>=0 && col<totalCol) return true;
        return false;
    }


    void bfs(int sr, int sc, int oldColor, int newColor, vector<vector<int>>&image){
        queue<pair<int,int>>q;
        q.push({sr, sc});
        image[sr][sc]=newColor;

        vector<pair<int,int>>directions = {{-1,0}, {1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            for (int i=0;i<directions.size();i++){
                int newr = cr+directions[i].first;
                int newc = cc+directions[i].second;

                if (isValid(newr, newc, image) && image[newr][newc]==oldColor){
                    image[newr][newc]=newColor;
                    q.push({newr, newc});
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if (oldColor == color) return image;

        vector<vector<int>> new_image = image;
        bfs(sr, sc, oldColor, color, new_image);
        return new_image;
    }
};