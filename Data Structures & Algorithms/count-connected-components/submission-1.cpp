class Solution {
public:
    void dfs(vector<int> adj[],vector<bool> &vis,int u){
        vis[u]=true;
        for(auto it:adj[u]){
            if(vis[it]!=true)
                dfs(adj,vis,it);
        }
    }
    void bfs(vector<int> adj[],vector<bool> &vis,int u,queue<int> &q){
        vis[u]=true;
        q.push(u);
        while(!q.empty()){
            int v=q.front();
            q.pop();
            for(auto it:adj[v]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=true;
                }
            }
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
        vector<bool> vis(n,false);
        int count=0;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                bfs(adj,vis,i,q);
                count++;
            }
        }
        return count;
    }
};
