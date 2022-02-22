class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int depth=0;
        int n=grid.size(),m=grid[0].size();
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                    q.push({{i, j}, depth});
            }
        }
        
        int ans=0;
        int rowIndex[]={0,0,1,-1};
        int colIndex[]={1,-1,0,0};
        
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int row=x.first.first;
            int col=x.first.second;
            int currDepth=x.second;
            ans=max(ans,currDepth);
            for(int i=0;i<4;i++){
                int rowPos=row+ rowIndex[i];
                int colPos=col+ colIndex[i];
                
                if(rowPos>=0 && rowPos<n && colPos>=0 && colPos<m && grid[rowPos][colPos]==1){
                    grid[rowPos][colPos]=2;
                    q.push({{rowPos,colPos},currDepth+1});
                }
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        
        return ans;
    }
};