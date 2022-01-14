class Solution {
public:
    bool isPal(string s){
        string str="";
        str+=s;
        reverse(str.begin(), str.end());
        return (str==s);
    }
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        string pal="";
        for(int i=0; i<n; i++){
            if(isPal(words[i])){
                pal+=words[i];
                break;
            }
        }
        return pal;
    }
};