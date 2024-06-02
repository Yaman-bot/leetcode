class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    int profit = 0;
                    if (buy)
                    { // Take                                  //Not take
                        profit = max(-prices[i] + ahead[0][cap], 0 + ahead[1][cap]);
                    }
                    else // Sell
                    {    // Take                                  //Not take
                        profit = max(prices[i] + ahead[1][cap - 1], 0 + ahead[0][cap]);
                    }

                    curr[buy][cap] = profit;
                }
            }
            ahead = curr;
        }

        return ahead[1][2];
    }
};