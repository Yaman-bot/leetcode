class Solution {
public:
    int maxCoins(vector<int> &piles)
    {
        int n = piles.size(), ans = 0;
        sort(piles.begin(), piles.end());
        int i = 0, j = n - 2;
        while (i < n / 3)
        {
            ans += piles[j];
            i++;
            j -= 2;
        }
        return ans;
    }
};