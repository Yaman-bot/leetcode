class Solution {
public:
    string generateTheString(int n) {
        string s="";
        if(n%2==0){
            n=n-1;
            while(n--)
               s+='a';
            s+='b';
        }
        else if(n%2!=0){
            while(n--)
                s+='a';
        }
        return s;
    }
};