 char keypad[][10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
class Solution {
public:
 
    void helper(string digits,string s,vector<string> &v,int idx){
        if(digits[idx]=='\0'){
            v.push_back(s);
            return ;
        }
        int digit=digits[idx]-'0';
        if(digit==0 || digit ==1)
            helper(digits,s,v,idx+1);
        for(int k=0;k<keypad[digit][k]!='\0';k++){
            helper(digits,s+keypad[digit][k],v,idx+1);
        }
        return ;
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> v;
        if(digits.size()==0) return v;
        string s;
        helper(digits,s,v,0);
        return v;
    }
};