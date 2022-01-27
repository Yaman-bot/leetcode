class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        int *dp = new int[nums.size()];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i <nums.size(); i++)
        {
            int val = nums[i];
            dp[i] = max(dp[i - 1], dp[i - 2] + val);
        }
        return dp[nums.size() - 1];
    }
};