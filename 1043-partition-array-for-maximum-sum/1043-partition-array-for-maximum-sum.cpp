class Solution
{
public:
    int f(int i, int n, vector<int> &dp, vector<int> &arr, int k)
    {
        if(i==n)
            return 0;

        if(dp[i]!=-1)
            return dp[i];

        int ans = -1e9, len = 0, maxi = -1e9;
        for (int j = i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=(len*maxi)+f(j+1,n,dp,arr,k);
            ans=max(ans,sum);
        }
        dp[i] = ans;
        return dp[i];
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int n=arr.size();
        vector<int> dp(n,-1);
        return f(0, n, dp, arr,k);
    }
};