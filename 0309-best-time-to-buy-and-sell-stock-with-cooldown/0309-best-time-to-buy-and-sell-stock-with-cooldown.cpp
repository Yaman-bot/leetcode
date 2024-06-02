class Solution
{
public:
    int f(int i, int buy, int n, vector<vector<int>> &dp, vector<int> &prices)
    {
        if (i >= n)
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        int profit = 0;
        if (buy)
        { // Take                                  //Not take
            profit = max(-prices[i] + f(i + 1, 0, n, dp, prices), 0 + f(i + 1, 1, n, dp, prices));
        }
        else // Sell
        {    // Take                                  //Not take
            profit = max(prices[i] + f(i + 2, 1, n, dp, prices), 0 + f(i + 1, 0, n, dp, prices));
        }

        dp[i][buy] = profit;
        return dp[i][buy];
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        //(index,buy)
        return f(0, 1, n, dp, prices);
    }
};