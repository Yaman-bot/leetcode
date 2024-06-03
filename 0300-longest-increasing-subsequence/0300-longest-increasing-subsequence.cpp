class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ahead(n+1,0),curr(n+1,0);

        for (int ind = n - 1; ind >= 0;ind--){
            for (int prev_ind = ind - 1;prev_ind >= -1;prev_ind--){
                int notTake = ahead[prev_ind + 1];
                int take = 0;
                if (prev_ind == -1 || nums[ind] > nums[prev_ind])
                    take = 1 + ahead[ind + 1];
                curr[prev_ind + 1] = max(notTake, take);
            }
            ahead=curr;
        }
        return ahead[-1 + 1];
    }
};