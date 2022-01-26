class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int n = stones.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += stones[i];

        vector<bool> dp(sum + 1);
        dp[0] = true;

        for (auto stone : stones)
            for (int s = sum; s >= stone; s--)
                if (dp[s - stone] || s == stone)
                    dp[s] = true;

        int sum1 = 0;
        for (int i = sum / 2; i >= 0; i--)
        {
            if (dp[i] == true)
            {
                sum1 = i;
                break;
            }
        }

        int sum2 = sum - sum1;
        return abs(sum2 - sum1);
    }
};