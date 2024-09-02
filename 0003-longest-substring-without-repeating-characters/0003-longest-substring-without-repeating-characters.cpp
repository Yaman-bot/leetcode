class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> mp;
        int l=0,r=0,ans=0;
        int n=s.size();
        while(r<n){
            if(mp.find(s[r])!=mp.end()){
                if(mp[s[r]]>=l)
                    l=mp[s[r]]+1;
            }
            int len=r-l+1;
            ans=max(ans,len);
            mp[s[r]]=r;
            r++;
        }
        return ans;
    }
};