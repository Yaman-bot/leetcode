class Solution
{
public:
    int f(int i, int transaction, int k, int n, vector<vector<int>> &dp, vector<int> &prices)
    {
        if (i == n || transaction == 2*k)
            return 0;

        if (dp[i][transaction] != -1)
            return dp[i][transaction];

        int profit = 0;
        if (transaction%2 == 0) //Buy
        {                                   // Take                                  //Not take
            profit = max(-prices[i] + f(i + 1, transaction+1, k, n, dp, prices), 0 + f(i + 1, transaction, k, n, dp, prices));
        }
        else // Sell
        {                               // Take                                  //Not take
            profit = max(prices[i] + f(i + 1, transaction + 1, k, n, dp, prices), 0 + f(i + 1, transaction, k, n, dp, prices));
        }

        dp[i][transaction] = profit;
        return dp[i][transaction];
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2*k,-1));
        //(index,buy,cap)
        return f(0, 0, k, n, dp, prices);
    }
};