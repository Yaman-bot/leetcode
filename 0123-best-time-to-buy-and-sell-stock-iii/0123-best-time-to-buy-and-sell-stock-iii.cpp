class Solution
{
public:
    int f(int i, int buy, int cap, int n, vector<vector<vector<int>>> &dp, vector<int> &prices)
    {
        if (i == n || cap==0)
            return 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        int profit = 0;
        if (buy)
        { // Take                                  //Not take
            profit = max(-prices[i] + f(i + 1, 0,cap, n, dp, prices), 0 + f(i + 1, 1,cap, n, dp, prices));
        }
        else // Sell
        {    // Take                                  //Not take
            profit = max(prices[i] + f(i + 1, 1,cap-1, n, dp, prices), 0 + f(i + 1, 0,cap, n, dp, prices));
        }

        dp[i][buy][cap] = profit;
        return dp[i][buy][cap];
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));

        //(index,buy,cap)
        return f(0, 1,2, n, dp, prices);
    }
};