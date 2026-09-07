class Solution {
public:
    bool check(vector<string> &grid,int row,int col){
        //row
        for(int i=0;i<grid.size();i++){
            if(grid[row][i]=='Q')
                return false;
        }
        //col
        for(int i=0;i<grid.size();i++){
            if(grid[i][col]=='Q')
                return false;
        }
        //left diagonal
        int r=row-1;
        int c=col-1;
        while(r>=0 && c>=0){
            if(grid[r][c]=='Q')
                return false;
            r--;
            c--;
        }
        r=row-1;
        c=col+1;
        while(r>=0 && c<grid.size()){
            if(grid[r][c]=='Q')
                return false;
            r--;
            c++;
        }
        return true;
    }
    void helper(vector<string> &grid,int row, vector<vector<string>> &ans){
        if(row==grid.size()){
            ans.push_back(grid);
            return;
        }
        for(int col=0;col<grid.size();col++){

            if(check(grid,row,col)){
                grid[row][col]='Q';
                helper(grid,row+1, ans);
                grid[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        vector<vector<string>> ans;
        helper(grid, 0, ans);
        return ans;
    }
};
