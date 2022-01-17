class Solution {
public:
     int solve(int start,int end,vector<int>&nums,bool flag){
        if(start>end)
            return 0;
         if(flag)
            return max(nums[start]+solve(start+1,end,nums,false),nums[end] +solve(start,end-1,nums,false));
         else
             return min(solve(start+1,end,nums,true),solve(start,end-1,nums,true));
    }
    bool PredictTheWinner(vector<int> nums) {
        int n=nums.size();
        int p1= solve(0,n-1,nums,true);
        int p2=0,sum=0;
        for(auto x:nums){
            sum+=x;
        }
        p2=sum-p1;
        cout<<p1<<" "<<p2<<endl;
        return p1>=p2 ? true :false;
    }
};