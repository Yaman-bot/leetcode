class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs=0;
        int ms=INT_MIN;
        int n=nums.size();
        if (n==1) return nums[0];
        for(int i=0;i<n;i++){
            cs+=nums[i];
            //If all numbers are -ve
            ms=max(ms,cs);
			if(cs < 0) {
			    cs = 0;
			}
        }
        return ms;
    }
};