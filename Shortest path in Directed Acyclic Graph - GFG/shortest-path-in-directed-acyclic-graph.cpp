//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[])
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it.first])
            {
                findTopoSort(it.first, vis, st, adj);
            }
        }
        st.push(node);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        stack<int> st;
        vector<int> vis(N,0);
        for (int i = 0; i < N; i++)
            if (!vis[i])
                findTopoSort(i, vis, st, adj);
                
        vector<int> dist(N,1e9);
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
            
            for(auto nbr:adj[node]){
                int v=nbr.first;
                int wt=nbr.second;
                
                if(dist[node]+wt<dist[v])
                    dist[v]=dist[node]+wt;
            }
        }
      for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
      return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends