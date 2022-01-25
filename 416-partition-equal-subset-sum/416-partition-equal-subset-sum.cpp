class Solution {
public:
   bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if (sum % 2 != 0) {
          return false;
        }
        
        sum=sum/2;

        vector<vector<bool>> dp(nums.size(), vector<bool>(sum + 1));
        int n=nums.size();
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        
        for(int s=1;s<=sum;s++){
            dp[0][s]=(nums[0]==s ? true:false);
        }
        
        for (int i = 1; i < n; i++)
        {
            for (int s = 1; s <= sum; s++)
            {
                // if we can get the sum 's' without the number at index 'i'
                if (dp[i - 1][s])
                    dp[i][s] = dp[i - 1][s];
                // else if we can find a subset to get the remaining sum
                else if (s >= nums[i])
                    dp[i][s] = dp[i - 1][s - nums[i]];
            }
        }
        
        return dp[n-1][sum];
    }
};