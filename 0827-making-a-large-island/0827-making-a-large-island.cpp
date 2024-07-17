class DisjointSet
{

public:
    vector<int> parent, size;
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
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0)
                    continue;
                for(int i=0;i<4;i++){
                    int adjRow = row + dr[i];
                    int adjCol = col + dc[i];
                    if (adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < n)
                    {
                        if(grid[adjRow][adjCol]==1){
                            int nodeNo = row * n + col;
                            int adjNodeNo = adjRow * n + adjCol;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }
        
        //0->1s
        int ans=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1)
                    continue;
                set<int> s;
                for(int i=0;i<4;i++){
                    int adjRow = row + dr[i];
                    int adjCol = col + dc[i];
                    if (adjRow >= 0 && adjRow < n && adjCol >= 0 && adjCol < n)
                    {
                        if(grid[adjRow][adjCol]==1){
                            int adjNodeNo = adjRow * n + adjCol;
                            s.insert(ds.findUltimateParent(adjNodeNo));
                        }
                    }
                }
                                     
                int sizeTotal=1;
                for(auto it:s){
                    sizeTotal+=ds.size[it];
                }
                ans=max(ans,sizeTotal);
            }
        }
                                     
        for(int i=0;i<n*n;i++){
            ans=max(ans,ds.size[ds.findUltimateParent(i)]);
        }
        return ans;
    }
};