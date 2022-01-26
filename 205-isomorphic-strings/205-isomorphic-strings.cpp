class Solution {
public:

    bool isIsomorphic(string s, string t) {
        map<char,char>m,m1;
        int n=s.length();
        if(n!=t.length()) 
            return false;
        for(int i=0; i<n; i++){
            if(m.count(s[i])==1){
                if(m[s[i]]!=t[i]) 
                    return false;
            }
            else{
                if(m1[t[i]]=='1') 
                    return false;
                m[s[i]]=t[i];
                m1[t[i]]='1';
            }
        }
        return true;
    }
};