class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> dp(n+1, 0);

        for (int i = n - 1; i >= 0;i--){
            int ans = -1e9, len = 0, maxi = -1e9;
            for (int j = i; j < min(n, i + k); j++)
            {
                len++;
                maxi = max(maxi, arr[j]);
                int sum = (len * maxi) + dp[j + 1];
                ans = max(ans, sum);
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};