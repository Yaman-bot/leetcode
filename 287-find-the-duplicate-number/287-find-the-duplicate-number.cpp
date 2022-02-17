class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        
        while(1){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast){
                break;
            }
        }
        int curr=nums[0];
        while(curr!=slow){
            curr = nums[curr];
            slow = nums[slow];
        }
        return curr;
    }
};