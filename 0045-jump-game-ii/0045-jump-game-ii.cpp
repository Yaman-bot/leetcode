class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0,left=0,right=0;
        while(right<nums.size()-1){
            int farthest=0;
            for(int i=left;i<=right;i++)
                farthest=max(i+nums[i],farthest);
            left=right+1;
            right=farthest;
            jumps++;
        }
        return jumps;
    }
};