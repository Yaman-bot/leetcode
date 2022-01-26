class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       
        int n = nums.size();
        int arrSum = accumulate(nums.begin(), nums.end(), 0);
        int sum = (target + arrSum)/2;
        
        if(sum > arrSum || (arrSum + target)%2!=0 || sum<0) return 0;
        
        
        vector<int> dp(sum+1, 0);
        dp[0] = 1;
        
        for(int i=0; i<n; i++){
            for(int j=sum; j>=nums[i]; j--)
                dp[j] += dp[j-nums[i]];
        }
        
        return dp[sum];
    }
};