class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(m>n)
            return "";
        int l=0,r=0,startInd=-1,cnt=0,minLen=INT_MAX;
        unordered_map<char,int> mp;
        for(int i=0;i<m;i++)
            mp[t[i]]++;
        
        while(r<n){
            if(mp[s[r]]>0) //Encountered a char in s which is in t
                cnt++;
            mp[s[r]]--;
            //Shrink the window
            while(cnt==m){
                int len=r-l+1;
                if(len<minLen){
                    minLen=len;
                    startInd=l;
                }
                mp[s[l]]++; //Restore the hash
                if(mp[s[l]]>0)
                    cnt--;
                l++;
            }
            r++;
        }
        if(startInd==-1)
            return "";
        return s.substr(startInd,minLen);
    }
};