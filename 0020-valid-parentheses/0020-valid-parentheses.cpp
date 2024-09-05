class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='[')
                st.push(ch);
            else{
                if(st.empty())
                    return false;
                char ch_top=st.top();
                st.pop();
                if(ch_top=='('&& ch!=')')
                    return false;
                if(ch_top=='['&& ch!=']')
                    return false;
                if(ch_top=='{'&& ch!='}')
                    return false;
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};