class Solution {
public:
    bool isValid(int row, int col, int val, vector<vector<char>>& board){
        int start_row = row - (row%3);
        int start_col = col - (col%3);
        int end_row = start_row+2;
        int end_col = start_col+2;

        
        // validating rows
        
        for(int i=0; i<9;i++){
            if(board[row][i] == val+'0') return false;
        }
        
        // validating columns
        
        for(int i=0; i<9;i++){
            if(board[i][col] == val+'0') return false;
        }

        // validating subgrid
        
        for (int i=start_row;i<=end_row;i++){
            for (int j=start_col;j<=end_col;j++){
                if(board[i][j] == val+'0') return false;
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& board){

       
        for (int i =0;i<9;i++){
            for (int j=0;j<9;j++){
                if (board[i][j]=='.'){
                    for (int val=1;val<=9;val++){
                        if (isValid(i, j, val, board)){
                            board[i][j] = val + '0';
                            if (solve(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {

        solve(board);
    }
};