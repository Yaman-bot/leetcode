class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n=name.length();
        int t=typed.length();
        if(n>t) return false;
        int i=0,j=0;
        while(i<n && j<t){
            if(name[i]==typed[j]){
                i++;
                j++;
            }
            else if(i>0 && name[i-1]==typed[j])
                j++;
            //name-> abcc
            //typed-> ac
            else 
                return false;
        }
        
        //name-> aabbc
        //tyoed-> aabbccd
        while(j<t){
             if (name[i - 1] != typed[j])
                return false;
            j++;
        }
        
        //name-> aabbcc
        //typed-> aaabbb
        if(i<n) 
            return false;
        return true;
    }
};