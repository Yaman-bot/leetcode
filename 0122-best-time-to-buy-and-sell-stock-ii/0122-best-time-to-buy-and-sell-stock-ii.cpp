class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int aheadBuy,aheadNotBuy,currBuy,currNotBuy;
        aheadBuy = aheadNotBuy= 0;

        for (int i = n - 1; i >= 0; i--)
        {
            currNotBuy=max(prices[i] + aheadBuy, 0 + aheadNotBuy);

            currBuy = max(-prices[i] + aheadNotBuy, 0 + aheadBuy);

            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return currBuy;
    }
};