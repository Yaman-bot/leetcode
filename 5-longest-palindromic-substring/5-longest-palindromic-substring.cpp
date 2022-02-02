class Solution
{
    public:
    string longestPalindrome(string s){
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        string ans="";
        int maxLen=1;

        for(int i=0;i<n;i++)
            dp[i][i]=true;

        for(int start=n-2;start>=0;start--){
            for(int end=start+1;end<n;end++){
                if(s[start]==s[end]){
                    // if it's a two character string or if the remaining string is a palindrome too
                    if(end-start==1 || dp[start+1][end-1]==true){
                        dp[start][end]=true;
                        if(end-start+1> maxLen){
                            ans=s.substr(start,end-start+1);
                            maxLen=end-start+1;
                        }
                    }
                }
            }
        }
        string altAns="";
        altAns+=s[0];
        if(maxLen>1)
            return ans;
        return altAns;
    }
};