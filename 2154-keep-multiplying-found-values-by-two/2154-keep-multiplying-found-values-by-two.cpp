class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int> m;
        for(auto num:nums)
            m[num]++;
        
        while(m.find(original)!=m.end()){
            original=original*2;
        }
        return original;
    }
};