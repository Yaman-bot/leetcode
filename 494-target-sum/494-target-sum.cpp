class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
            totalSum += nums[i];
        
        int newTarget = (totalSum + target) / 2;
        
        if (totalSum <abs(target) || (target + totalSum) % 2 != 0 || newTarget<0 )
            return 0;
    
        vector<int> dp(newTarget + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = newTarget; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[newTarget];
    }
};