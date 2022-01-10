class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parens;
        string paren;
        helper(n,0,0,paren,parens);
        return parens;
    }
    
    void helper(int n,int open,int close,string paren,vector<string> &parens){
        if(open==n && close==n){
            parens.push_back(paren);
            return ;
        }
        if(open<n)
            helper(n,open+1,close,paren+'(',parens);
        if(close<open)
             helper(n,open,close+1,paren+')',parens);
        return ;
    }
};