class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        int ans=1;
        temp.push_back(nums[0]);
        for(int i=0;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                ans++;
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return ans;
    }
};