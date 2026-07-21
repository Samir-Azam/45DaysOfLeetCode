class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row0 = 1;

        // marking
        for (int i=0;i<rows;i++){
            for (int j=0;j<cols;j++){
                if (matrix[i][j]==0){
                    matrix[0][j]=0;
                    if (i==0) row0 = 0;
                    else matrix[i][0] = 0;
                }
            }
        }

        // go for rows first



        for (int i=1;i<rows;i++){
            if (matrix[i][0]==0){
                for (int j=0;j<cols;j++){
                    matrix[i][j]=0;
                }
            }
        }

        for (int i=0;i<cols;i++){
            if (matrix[0][i]==0){
                for (int j=0;j<rows;j++){
                    matrix[j][i]=0;
                }
            }
        }

        if (row0 == 0){
            for (int i=0;i<cols;i++){
                matrix[0][i] = 0;
            }
        }
        
    }
};