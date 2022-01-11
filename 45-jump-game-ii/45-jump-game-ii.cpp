class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1 || nums[0]==0) return 0;
        int cur_reach=0;
        int max_reach=0;
        int jumps=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]+i>max_reach){
                max_reach=nums[i]+i;
            }
             if(i==cur_reach)
            {
                jumps++;
                cur_reach=max_reach;
            }
        }
        return jumps;
    }
};