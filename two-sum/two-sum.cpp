class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> res;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            int rem=target-nums[i];
            
            if(m.find(rem)!=m.end()){
                res.push_back(m[rem]);
                res.push_back(i);
                return res;
            }
            
            m[nums[i]]=i;
        }
        return res;
    }
};