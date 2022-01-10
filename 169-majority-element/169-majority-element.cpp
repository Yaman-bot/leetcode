class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele;
        int cnt=0;
        for(auto num:nums){
            if(cnt==0)
                ele=num;
            if(num==ele)
                cnt++;
            else
                cnt--;
        }
        return ele;
    }
};