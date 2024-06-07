class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &dp, vector<int> &cuts)
    {
        if(i>j)
            return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        int mini = 1e9;
        for (int ind = i;ind<=j;ind++){
            int cost=cuts[j+1]-cuts[i-1] + f(i,ind-1,dp,cuts) + f(ind+1,j,dp,cuts);
            mini=min(mini,cost);
        }

        dp[i][j] = mini;
        return dp[i][j];
    }
    int minCost(int n, vector<int> &cuts)
    {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        return f(1,c,dp,cuts);
    }
};