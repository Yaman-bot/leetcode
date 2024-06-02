class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<int> ahead(2 * k + 1, 0),curr(2 * k + 1,0);

        // Base case
        // For i==n && transaction==2*k dp[i][transaction]=0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int transaction = 2 * k - 1; transaction >= 0; transaction--)
            {
                int profit = 0;
                if (transaction % 2 == 0) // Buy
                {                         // Take                                  //Not take
                    profit = max(-prices[i] + ahead[transaction + 1], 0 + ahead[transaction]);
                }
                else // Sell
                {    // Take                                  //Not take
                    profit = max(prices[i] + ahead[transaction + 1], 0 + ahead[transaction]);
                }

                curr[transaction] = profit;
            }
            ahead = curr;
        }

        return ahead[0];
    }
};