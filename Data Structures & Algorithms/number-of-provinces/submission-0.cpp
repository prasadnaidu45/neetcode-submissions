class Solution {
public:
    void dfs(vector<int> adj[],int u,vector<bool> &vis){
        vis[u]=true;
        for(auto it:adj[u]){
            if(vis[it]==false)
                 dfs(adj,it,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> vis(n,false);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(adj,i,vis);
                count++;
            }
        }
        return count;
    }
};