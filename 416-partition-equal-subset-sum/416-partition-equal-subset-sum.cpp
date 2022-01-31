class Solution {
public:
    bool canPartition(const vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];

        if (sum % 2 != 0)
            return false;

        sum /= 2;
        vector<bool> dp(sum + 1);
        dp[0] = true;

        for (auto num : nums)
            for (int s = sum; s >= num; s--)
                if (dp[s - num] )
                    dp[s] = true;

        return dp[sum];
    }
};