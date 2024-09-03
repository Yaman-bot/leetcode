class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,ans=0;
        unordered_map<int,int> mpp;
        while(r<fruits.size()){
            mpp[fruits[r]]++;
            
                if(mpp.size()>2){
                    mpp[fruits[l]]--;
                    if(mpp[fruits[l]]==0)
                        mpp.erase(fruits[l]);
                    l++;   
                }
            if(mpp.size()<=2){
                int len=r-l+1;
                ans=max(ans,len);   
            }
            r++;
        }
        return ans;
    }
};