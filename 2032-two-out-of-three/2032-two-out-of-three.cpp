class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> a1(101,0);
        vector<int> a2(101,0);
        vector<int> a3(101,0);
        vector<int> ans;
    
        
        for(int &i:nums1)
            a1[i]=1;
         for(int &i:nums2)
             a2[i]=1;
         for(int &i:nums3)
             a3[i]=1;
        
        for(int i=1;i<101;i++){
            if(a1[i]+a2[i]+a3[i]>=2)
                ans.push_back(i);
        }
        
        return ans;
    }
};