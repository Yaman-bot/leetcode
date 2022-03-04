// Space Optimization-O(M)
//Time-O(N*M)
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp(m, 0);

        for (int j = 0; j < m; j++)
            dp[j] = matrix[0][j];

        for (int i = 1; i < n; i++)
        {
            vector<int> temp(m, 0);
            for (int j = 0; j < m; j++)
            {
                int up = dp[j] + matrix[i][j];
                int leftDiagonal = matrix[i][j];
                if (j - 1 >= 0)
                    leftDiagonal += dp[j - 1];
                else
                    leftDiagonal += 1e9;
                int rightDiagonal = matrix[i][j];
                if (j + 1 < m)
                    rightDiagonal += dp[j + 1];
                else
                    rightDiagonal += 1e9;
                temp[j] = min(up, min(leftDiagonal, rightDiagonal));
            }
            dp = temp;
        }
        int ans = 1e9;
        for (int j = 0; j < m; j++)
            ans = min(ans, dp[j]);
        return ans;
    }
};