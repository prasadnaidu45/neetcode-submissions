class Solution {
public:
    void dfs(vector<vector<char>> &grid,int row,int col){
        grid[row][col]='0';
        int rows[]={-1,0,1,0};
        int cols[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int drow=row+rows[i];
            int dcol=col+cols[i];
            if(0<=drow && drow<grid.size() && 0<=dcol && dcol<grid[0].size()){
                if(grid[drow][dcol]!='0'){
                    dfs(grid,drow,dcol);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!='0'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
