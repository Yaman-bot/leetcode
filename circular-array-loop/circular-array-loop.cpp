class Solution {
public:
    int next(vector<int>& nums,int index){
        return (index+nums[index]+nums.size())%nums.size();
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int slow=i,fast=i;
            while (
                   nums[slow] * nums[next(nums, slow)] > 0 
                   && nums[fast] * nums[next(nums, fast)] > 0 
                   && nums[fast] * nums[next(nums, next(nums, fast))] > 0
            )
            {
                slow=next(nums,slow);
                fast=next(nums,next(nums,fast));
                if(slow==fast){
                    if(slow==next(nums,slow))
                        break;
                    return true;
                }
            }
                
            slow = i;
            int val = nums[slow];
            while (val * nums[slow] > 0)
            {
                int temp = slow;
                slow = next(nums, slow);
                nums[temp] = 0;
            }

        }
        return false;
    }
};