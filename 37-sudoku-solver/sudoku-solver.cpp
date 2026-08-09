class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    //for returning true in every case when possible
    bool solve (vector<vector<char>>& board){
        int n = board.size(),m = board[0].size();
        for(int i =0 ;i<n;i++){
            for(int j =0 ;j<m;j++){
                if(board[i][j]=='.'){
                    for(char k ='1';k<='9';k++){
                        if(isvalid(board, i , j ,k )){
                            board [i][j]  =k;
                            if(solve(board)==true)
                               return true;
                            else
                               board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isvalid(vector<vector<char>>& board, int row, int col,char val){
           for(int i =0; i<9;i++){
              //check row
              if(board[i][col]==val)return false;
              //check col
              if(board[row][i]==val)return false;
              //checking in subsudoku
              if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)return false;
           }
           return true;
    }
};