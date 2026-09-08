class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(image.size(),vector<bool>(image[0].size(),false));
        q.push({sr,sc});
        int prevcolor=image[sr][sc];
        if(prevcolor==color)
            return image;
        image[sr][sc]=color;
        vis[sr][sc]=true;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int r=row+drow[i];
                int c=col+dcol[i];
                if((r>=0 && r<image.size()) && (c>=0 && c<image[0].size())){
                   if(image[r][c]==prevcolor && vis[r][c]==false){
                    q.push({r,c});
                    image[r][c]=color;
                    vis[r][c]=true;
                   }
                }
            }
        }
        return image;
    }
};