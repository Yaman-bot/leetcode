class Solution {
public:
    int thirdMax(vector<int>& nums)
    {  
          sort(nums.begin(),nums.end());  
          nums.erase(unique(nums.begin(),nums.end()),nums.end());   
          if(nums.size()>2)
              return nums[nums.size()-3];        
          else if(nums.size()==2)
              return max(nums[0],nums[1]);
          else
              return nums[0];
    }
};