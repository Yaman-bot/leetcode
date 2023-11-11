//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    void dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid,
             int n, int m, int pr, int pc, vector<pair<int, int>> &vec)
    {
        if (r < 0 || c < 0 || r >= n || c >= m)
            return;
        if (grid[r][c] == 0 || vis[r][c]==1)
            return;

        vis[r][c] = 1;
        vec.push_back({r - pr, c - pc});
        dfs(r - 1, c, vis, grid, n, m, pr, pc, vec);
        dfs(r + 1, c, vis, grid, n, m, pr, pc, vec);
        dfs(r, c - 1, vis, grid, n, m, pr, pc, vec);
        dfs(r, c + 1, vis, grid, n, m, pr, pc, vec);
        return;
    }
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, vis, grid, n, m, i, j, vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends