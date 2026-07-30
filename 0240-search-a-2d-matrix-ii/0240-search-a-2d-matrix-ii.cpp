class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        // for bottomLeft
        int i = rows-1;
        int j = 0;

        while (i>=0 && j<cols){
            int val = matrix[i][j];
            if (val==target) return true;
            else if (val>target) i--;
            else j++;
        }
        return false;
    }
};