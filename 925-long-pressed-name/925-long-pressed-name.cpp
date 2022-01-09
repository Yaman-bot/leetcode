class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.length()>typed.length())
            return false;
        int i=0,j=0;
        while(i<name.length() && j<typed.length()){
            if(name[i]==typed[j]){
                i++;
                j++;
            }
            else if(i>0 && name[i-1]==typed[j])
                j++;
            else 
                return false;
        }
        
        while(j<typed.length()){
            if(name[i-1]!=typed[j])
                return false;
            j++;
        }
        
        if(i<name.length())
            return false;
        return true;
    }
};