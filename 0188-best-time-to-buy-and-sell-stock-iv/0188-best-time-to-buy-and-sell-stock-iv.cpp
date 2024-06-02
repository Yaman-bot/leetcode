class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2 * k+1, 0));

        // Base case
        // For i==n && transaction==2*k dp[i][transaction]=0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int transaction = 2 * k - 1;transaction>=0;transaction--){
                int profit = 0;
                if (transaction % 2 == 0) // Buy
                {                         // Take                                  //Not take
                    profit = max(-prices[i] + dp[i + 1][transaction + 1], 0 + dp[i + 1][transaction]);
                }
                else // Sell
                {    // Take                                  //Not take
                    profit = max(prices[i] + dp[i + 1][transaction + 1], 0 + dp[i + 1][transaction]);
                }

                dp[i][transaction] = profit;
            }
        }

        return dp[0][0];
    }
};