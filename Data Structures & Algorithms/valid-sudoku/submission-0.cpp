class Solution {
public:
    bool check(vector<vector<char>>& board,int row,int col){
        //row
            for(int i=0;i<9;i++){
                if(i==col )
                    continue;
                if(board[row][i]==board[row][col])
                    return false;
            }
        //col
            for(int i=0;i<9;i++){
                if(i==row )
                    continue;
                if(board[i][col]==board[row][col])
                    return false;
            }
        //box
            int r=(row/3)*3;
            int c=(col/3)*3;
            for(int i=r;i<r+3;i++){
                for(int j=c;j<c+3;j++){
                    if(i==row && j==col)
                        continue;
                    if(board[i][j]==board[row][col])
                        return false;
                }
            }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                else if(!check(board,i,j))
                    return false;
            }
        }
        return true;
    }
};
