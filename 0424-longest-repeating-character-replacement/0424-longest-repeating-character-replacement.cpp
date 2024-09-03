class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,ans=0,maxf=0;
        unordered_map<char,int> mpp;
        while(r<s.size()){
            mpp[s[r]]++;
            maxf=max(maxf,mpp[s[r]]);
            int len=r-l+1;
            if(len-maxf>k){
                mpp[s[l]]--;
                l++;
            }
            if(len-maxf<=k)
                ans=max(ans,len);
            r++;
        }
        return ans;
    }
};