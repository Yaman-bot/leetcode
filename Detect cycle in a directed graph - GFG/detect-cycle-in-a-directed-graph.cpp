//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++){
	        for(auto it:adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;
	    
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)
	            q.push(i);
	    }
	    
	    vector<int> ans;
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(auto nbr:adj[node]){
	            indegree[nbr]--;
	            if(indegree[nbr]==0)
	                q.push(nbr);
	        }
	    }
	    return ans;
	}
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> topo=topoSort(V,adj);
        return !(topo.size()==V);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends