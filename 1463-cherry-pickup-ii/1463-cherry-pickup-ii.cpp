// Space OPtimized-O(N*M)
// Time-O(N*M*M)
class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                if (j1 == j2)
                    dp[j1][j2] = grid[n - 1][j1];
                else
                    dp[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            vector<vector<int>> temp(m, vector<int>(m, 0));
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {
                    int maxi = -1e9;
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int val = 0;
                            if (j1 == j2)
                                val = grid[i][j1];
                            else
                                val = grid[i][j1] + grid[i][j2];
                            if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                                val += dp[j1 + dj1][j2 + dj2];
                            else
                                val += -1e9;
                            maxi = max(maxi, val);
                        }
                    }
                    temp[j1][j2] = maxi;
                }
            }
            dp = temp;
        }
        return dp[0][m - 1];
    }
};