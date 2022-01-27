class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int n1=0,n2=nums[0],temp;
        for (int i = 1; i <nums.size(); i++)
        {
            int val = nums[i];
            temp = max(n2, n1 + val);
            n1=n2;
            n2=temp;
        }
        return n2;
    }
};