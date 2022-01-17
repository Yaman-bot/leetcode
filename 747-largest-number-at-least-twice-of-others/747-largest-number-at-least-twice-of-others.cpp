class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int max_index=0;
        int max_val=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(max_val<nums[i])
            {
                max_val=nums[i];
                max_index=i;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(i!=max_index and nums[max_index]<2*nums[i])
                return -1;
        }
        return max_index;
        
    }
       
};