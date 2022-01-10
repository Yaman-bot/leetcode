class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int ele1,ele2;
        int e1c=0,e2c=0;
        for(auto num:nums){
            if(num==ele1)
                e1c++;
            else if(num==ele2)
                e2c++;
            else if(e1c==0){
                ele1=num;
                e1c=1;
            }
            else if(e2c==0){
                ele2=num;
                e2c=1;
            }
            else{
                e1c--;
                e2c--;
            }
        }
        
        e1c=0,e2c=0;
        for(auto num:nums){
            if(num==ele1)
                e1c++;
            else if(num==ele2)
                e2c++;
        }
        if(e1c>nums.size()/3)
            ans.push_back(ele1);
        if(e2c>nums.size()/3)
            ans.push_back(ele2);
        return ans;
    }
    
};