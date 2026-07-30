class Solution {
public:
    int findMaxElement(vector<vector<int>>& mat, int col){
        int maxi = -1;
        int idx = -1;
        for (int i=0;i<mat.size();i++){
            if (mat[i][col]>maxi){
                maxi = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int low = 0;
        int high = col-1;
        while(low<=high){
            int mid = low+(high-low)/2;

            // row containing max
            int maxi = findMaxElement(mat, mid);
            int left = mid>0 ? mat[maxi][mid-1] :-1;
            int right = mid<col-1 ? mat[maxi][mid+1] :-1;
            
            int val = mat[maxi][mid];
            if (left<val && val>right) return {maxi, mid};
            else if (left<val) low = mid+1;
            else high = mid-1;
        }
        return {-1, -1};
    }
};