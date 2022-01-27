class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || nums[0]==0) return 0;
        int curr_reach=0,max_reach=0,jumps=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]+i>max_reach)
                max_reach=nums[i]+i;
            if(i==curr_reach){
                curr_reach=max_reach;
                jumps++;
            }
        }
        return jumps;
    }
};