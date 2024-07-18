class Solution {
public:
    int timer=0;
    void dfs(int node,int parent,vector<int> &vis,vector<int> &tin,vector<int> &low,
             vector<int> adj[],vector<vector<int>> &bridges){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent)
                continue;
            if(!vis[it]){
                dfs(it,node,vis,tin,low,adj,bridges);
                low[node]=min(low[it],low[node]);
                if(low[it]>tin[node])
                    bridges.push_back({it,node});
            }
            else
                low[node] = min(low[node], low[it]);
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0),tin(n,-1),low(n,-1);
        vector<vector<int>> bridges;
        dfs(0,-1,vis,tin,low,adj,bridges);
        return bridges;
    }
};