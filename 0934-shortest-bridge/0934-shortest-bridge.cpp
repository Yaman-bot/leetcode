class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, queue<pair<int, pair<int, int>>> &q)
    {
        vis[row][col] = 1;
        q.push({0, {row, col}});
        int rownum[] = {-1, 0, 1, 0};
        int colnum[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + rownum[i];
            int ncol = col + colnum[i];
            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == 1 &&!vis[nrow][ncol])
                dfs(nrow, ncol, grid, vis, q);
        }
    }
    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        int count = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        //Do DFS for first compononent
        for(int i = 0; i < n; i++){
            for (int j = 0;j<m; j++){
                if(grid[i][j]==1 && !vis[i][j] && count<1){
                    dfs(i,j,grid,vis,q);
                    count++;
                }
            }
        }

        int ans = 1e9;
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int dist = q.front().first;
            q.pop();
            int rownum[] = {-1, 0, 1, 0};
            int colnum[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + rownum[i];
                int ncol = col + colnum[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0 &&
                    !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({dist + 1, {nrow, ncol}});
                }
                else if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 &&
                        !vis[nrow][ncol]){
                    ans = min(ans, dist);
                }
            }
        }
        return ans;
    }
};