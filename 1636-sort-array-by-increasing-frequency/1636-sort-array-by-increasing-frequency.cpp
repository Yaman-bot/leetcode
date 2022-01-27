class Solution {
public:

     static bool cmp(pair<int,int> pair1, pair<int,int> pair2){
        if(pair2.second==pair1.second) 
            return pair1>pair2;
        return pair1.second<pair2.second;
    }


    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> m;
        
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        
        vector<pair<int,int>> v;
        
        for(auto i:m){
            v.push_back(i);
        }
        
        vector<int> res;
        
        sort(v.begin(),v.end(),cmp);;
        for(auto &i:v){
            while(i.second!=0){
                res.push_back(i.first);
                i.second--;
            }

        }
        return res;
    }

};