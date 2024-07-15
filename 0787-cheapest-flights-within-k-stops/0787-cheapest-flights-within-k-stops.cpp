class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        dist[src]=0;
        q.push({0,{src,0}});
        
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int wt=it.second.second;
            
            if (stops > k)
                continue;
            
            for(auto it:adj[node]){
                int nbr=it.first;
                int nbrWt=it.second;
                
                if(dist[nbr]>wt+nbrWt && stops<=k){
                    dist[nbr]=wt+nbrWt;
                    q.push({stops+1,{nbr,dist[nbr]}});
                }
            }
        }
        if(dist[dst]==1e9)
            return -1;
        return dist[dst];
    }
};