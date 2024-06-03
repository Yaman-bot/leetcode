class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int maxi=0;

        for (int ind = 0; ind <n;ind++){
            for (int prev = 0;prev<= ind-1;prev++){
                if(nums[ind]>nums[prev]){
                    dp[ind]=max(1+dp[prev],dp[ind]);
                }
            }
            maxi=max(maxi,dp[ind]);
        }
        return maxi;
    }
};