//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> s;
        vector<int> dist(V,1e9);
        dist[S]=0;
        s.insert({0,S});
        
        while(!s.empty()){
            auto it=*(s.begin());
            int wt=it.first;
            int node=it.second;
            s.erase(it);
            
            for(auto it:adj[node]){
                int nbrDist=it[1];
                int nbr=it[0];
                
                if(dist[nbr]>wt+nbrDist){
                    //Erase al
                    if(dist[nbr]!=1e9)
                        s.erase({dist[nbr],nbr});
                    dist[nbr]=wt+nbrDist;
                    s.insert({dist[nbr],nbr});
                }
            }
        }
        for(int i=0;i<V;i++)
            if(dist[i]==1e9)
                dist[i]=-1;
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends