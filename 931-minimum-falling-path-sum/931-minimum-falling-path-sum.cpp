//Top Down-O(N*M)
class Solution
{
public:
    int f(int i, int j, int n,int m, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if(j<0 || j>=m)
            return 1e9;
        if(i==0)
            return matrix[0][j];
        if(dp[i][j]!=-1)
            return dp[i][j];    

        int up=matrix[i][j]+f(i-1,j,n,m,matrix,dp);
        int leftDiagonal=matrix[i][j]+f(i-1,j-1,n,m,matrix,dp);
        int rightDiagonal=matrix[i][j]+f(i-1,j+1,n,m,matrix,dp);
        dp[i][j]=min(up,min(leftDiagonal,rightDiagonal));
        return dp[i][j];
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans=INT_MAX;
        for (int j = 0; j < m; j++)
        {
            int mini=f(n - 1, j, n,m, matrix, dp);
            ans=min(ans,mini);
        }
        return ans;
    }
};