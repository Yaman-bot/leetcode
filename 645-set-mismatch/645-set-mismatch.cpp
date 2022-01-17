class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>a;
        int n=nums.size(),k=0;
        // to find the sum of allelement of vactor
        for(int i=0;i<n;i++)
            k+=nums[i];
        // to find the duplicae element
        for(int i=0;i<nums.size();i++)
        {
            int index=abs(nums[i])-1;
            if(nums[index]<0)
                a.emplace_back(index+1);
            else
                nums[index]*=-1;
        }
        // to get the missing element from 1 to n
        int s=0;
        s=(n*(n+1))/2;
        a.emplace_back((s-k)+a[0]);
        return a;
    }
};