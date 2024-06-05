class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n, 1),dp2(n, 1);

        for (int ind = 0; ind < n; ind++)
        {
            for (int prev = 0; prev <= ind - 1; prev++)
            {
                if (nums[ind] > nums[prev])
                    dp1[ind] = max(1 + dp1[prev], dp1[ind]);
            }
        }

        for (int ind = n-1; ind >=0; ind--)
        {
            for (int prev = n-1; prev > ind; prev--)
            {
                if (nums[ind] > nums[prev])
                    dp2[ind] = max(1 + dp2[prev], dp2[ind]);
            }
        }

        int maxi = 1;
        for (int i = 0; i < n;i++){
            if(dp1[i] > 1 && dp2[i] > 1){
                maxi = max(maxi, dp1[i] + dp2[i] -1);
            }
        }
        return n-maxi;
    }
};