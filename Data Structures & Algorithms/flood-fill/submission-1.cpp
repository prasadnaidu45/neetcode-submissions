class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int prev_colour=image[sr][sc];
        image[sr][sc]=color;
        vis[sr][sc]=true;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int row=drow[i]+r;
                int col=dcol[i]+c;
                if(0<=row && row<n && 0<=col && col<m && image[row][col]==prev_colour && vis[row][col]==false){
                    image[row][col]=color;
                    vis[row][col]=true;
                    q.push({row,col});
                }
            }
        }
        return image;
    }
};