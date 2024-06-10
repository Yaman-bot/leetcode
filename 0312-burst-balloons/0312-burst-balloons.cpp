class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &dp, vector<int> &nums)
    {
        if(i>j)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        int maxi = -1e9;
        for (int ind = i;ind<=j;ind++){
            int cost = nums[i - 1] * nums[ind] * nums[j + 1] + f(i, ind - 1, dp, nums) + f(ind + 1, j, dp, nums);
            maxi=max(maxi, cost);
        }
        dp[i][j] = maxi;
        return dp[i][j];
    }
    int maxCoins(vector<int> &nums)
    {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return f(1,n,dp,nums);
    }
};