class Solution {
public:
    int f(int i,vector<int> &dp,vector<int>& nums){
        if(i<0)
            return 0;
        
        if(i==0)
            return nums[0];
        
        if(dp[i]!=-1)
            return dp[i];
        
        int pick=nums[i]+f(i-2,dp,nums);
        int notPick=f(i-1,dp,nums);
        dp[i]=max(pick,notPick);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=nums[i]+f(i-2,dp,nums);
            int notPick=f(i-1,dp,nums);
            dp[i]=max(pick,notPick);
        }
        
        return dp[n-1];
    }
};