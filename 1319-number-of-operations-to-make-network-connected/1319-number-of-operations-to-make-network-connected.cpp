class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extraEdges=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            
            if(ds.findUltimateParent(u)==ds.findUltimateParent(v)){
                extraEdges++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int cntC=0;
        for(int i=0;i<n;i++){
            if(ds.findUltimateParent(i)==i)
                cntC++;
        }
        int ans=cntC-1;
        if(extraEdges>=ans)
            return ans;
        return -1;
    }
};