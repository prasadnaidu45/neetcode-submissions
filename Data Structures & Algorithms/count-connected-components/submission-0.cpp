class Solution {
public:
    void dfs(vector<int> adj[],vector<bool> &vis,int u){
        vis[u]=true;
        for(auto it:adj[u]){
            if(vis[it]!=true)
                dfs(adj,vis,it);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(edges.size(),false);
        int count=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(adj,vis,i);
                count++;
            }
        }
        return count;
    }
};
