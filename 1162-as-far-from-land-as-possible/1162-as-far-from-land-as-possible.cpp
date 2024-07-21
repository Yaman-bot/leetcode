class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n=grid.size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                    cnt++;
                }
            }
        }
        if(q.empty() || cnt==n*n)
            return -1;
        int ans = 0;
        int rowIndex[] = {0, 0, -1, 1}; //right,left,up,down
        int colIndex[] = {1, -1, 0, 0};
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int currDepth=x.first;
            int row=x.second.first;
            int col=x.second.second;
            ans = max(ans, currDepth);
            for (int i = 0; i < 4; i++)
            {
                int rowPos = row + rowIndex[i];
                int colPos = col + colIndex[i];
                if (rowPos >= 0 && rowPos < n && colPos >= 0 && colPos < n && grid[rowPos][colPos] == 0 && !vis[rowPos][colPos])
                {
                    vis[rowPos][colPos] = 1;
                    q.push({currDepth + 1,{rowPos, colPos}});
                }
            }
        }
        
        
        
        return ans;
    }
};