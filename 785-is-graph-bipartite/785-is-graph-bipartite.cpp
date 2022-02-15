class Solution {
public:
    bool dfs(vector<int> &color,vector<vector<int>>& graph,int node){
        if(color[node]==-1)
            color[node]=1;
        for(auto nbr:graph[node]){
            if(color[nbr]==-1){
                color[nbr]=1-color[node];
                if(!dfs(color,graph,nbr))
                    return false;
            }
            if(color[nbr]==color[node])
                return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1 && !dfs(color,graph,i))
                return false;
        }
        return true;
    }
};