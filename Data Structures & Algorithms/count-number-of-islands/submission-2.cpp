class Solution {
public:
    void bfs(vector<vector<char>>& grid,int row,int col){
        grid[row][col]='0';
        queue<pair<int,int>> q;
        q.push({row,col});
        int rows[]={-1,0,1,0};
        int cols[]={0,1,0,-1};
    while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
        for(int i=0;i<4;i++){
            int drow=r+rows[i];
            int dcol=c+cols[i];
            if(0<=drow && drow<grid.size() && 0<=dcol && dcol<grid[0].size()){
                if(grid[drow][dcol]!='0'){
                    grid[drow][dcol]='0';
                    q.push({drow,dcol});
                }
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
                    bfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
