class Solution
{
public:
    int minCut(string s)
    {
        int n = s.length();
        vector<vector<bool>> dpPalindrome(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
            dpPalindrome[i][i] = true;

        for (int start = n - 1; start >= 0; start--)
        {
            for (int end = start + 1; end < n; end++)
            {
                if (s[start] == s[end])
                {
                    if (end - start == 1 || dpPalindrome[start + 1][end - 1])
                        dpPalindrome[start][end] = true;
                }
            }
        }

        vector<int> cuts(n, 0);
        for (int start = n - 1; start >= 0; start--)
        {
            int minCuts = n;
            for (int end = n - 1; end >= start; end--)
            {
                if (dpPalindrome[start][end])
                    minCuts = (end == n - 1) ? 0 : min(minCuts, cuts[end + 1] + 1);
            }
            cuts[start] = minCuts;
        }
        return cuts[0];
    }
};