#define ll long long

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll,ll>> adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({(ll)it[1],(ll)it[2]});
            adj[it[1]].push_back({(ll)it[0],(ll)it[2]});
        }
        
        vector<ll> dist(n,1e15);
        vector<ll> ways(n,0);
        
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        ll mod = 1e9 + 7;
        while(!pq.empty()){
            ll wt=pq.top().first;
            ll node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                ll nbr=it.first;
                ll nbrWt=it.second;
                
                if(dist[nbr]>wt+nbrWt){
                    dist[nbr]=wt+nbrWt;
                    pq.push({dist[nbr],nbr});
                    ways[nbr]=ways[node];
                }
                else if(dist[nbr]==wt+nbrWt){
                    ways[nbr] = (ways[nbr] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};