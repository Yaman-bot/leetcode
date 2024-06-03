class Solution {
public:
    int f(int ind,int prev_ind,int n,vector<vector<int>> &dp,vector<int>& nums){
        if(ind==n)
            return 0;

        if(dp[ind][prev_ind+1]!=-1)
            return dp[ind][prev_ind+1];

        int notTake=f(ind+1,prev_ind,n,dp,nums);
        int take=0;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind])
            take=1+f(ind+1,ind,n,dp,nums);
        dp[ind][prev_ind+1]=max(notTake,take);
        return dp[ind][prev_ind+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        //ind,prev_inde
        return f(0,-1,n,dp,nums);
    }
};