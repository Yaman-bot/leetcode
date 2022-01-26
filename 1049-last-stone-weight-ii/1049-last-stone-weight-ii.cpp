class Solution {
public:
    int lastStoneWeightII(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        vector<vector<bool>> dp(n, vector<bool>(sum / 2 + 1));

        // populate the sum=0 column, as we can always have '0' sum without including any element
        for (int i = 0; i < n; i++)
            dp[i][0] = true;

        // with only one number, we can form a subset only when the required sum is
        // equal to its value
        for (int s = 1; s <= sum / 2; s++)
            dp[0][s] = (nums[0] == s ? true : false);

        // process all subsets for all sums
        for (int i = 1; i < n; i++)
        {
            for (int s = 1; s <= sum / 2; s++)
            {
                // if we can get the sum 's' without the sber at index 'i'
                if (dp[i - 1][s])
                    dp[i][s] = dp[i - 1][s];
                // else if we can find a subset to get the remaining sum
                else if (s >= nums[i])
                    dp[i][s] = dp[i - 1][s - nums[i]];
            }
        }

        int sum1 = 0;
        for (int i = sum / 2; i >= 0; i--)
        {
            if (dp[n - 1][i] == true)
            {
                sum1 = i;
                break;
            }
        }

        int sum2 = sum - sum1;
        return abs(sum2 - sum1);
    }
};