class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<int> adj[]){
        vis[node]=1;
        
        for(auto nbr:adj[node]){
            if(!vis[nbr])
                dfs(nbr,vis,adj);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected[0].size();
        vector<int> vis(v,0);
        vector<int> adj[v];
        
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                ans++;
                dfs(i,vis,adj);
            }
        }
        return ans;
    }
};