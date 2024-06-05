#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool checkPossible(string &s1, string &s2)
    {
        if(s1.size() != s2.size()+1)
            return false;

        int first=0,second=0;

        while(first < s1.size()){
            if(second<s2.size() && s1[first] == s2[second]){
                first++;
                second++;
            }
            else
                first++;
        }

        if(first == s1.size() && second == s2.size())
            return true;
        return false;
    }

    static bool compare(string &s1, string &s2){
        return s1.size()<s2.size();
    }

    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(),compare);
        int n=words.size();
        int maxi=0;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for(int prev=0; prev<=i-1; prev++){
                if(checkPossible(words[i], words[prev]))
                    dp[i]=max(dp[i],1+dp[prev]);
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};