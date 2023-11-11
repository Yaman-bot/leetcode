//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, vector<pair<int,int>> &v, 
             int row0, int col0) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(row<0 || row>=n || col<0 || col>=m ) 
            return ;
        
        
        if(grid[row][col] == 0 || vis[row][col] == 1)
            return;
        
        vis[row][col] = 1;
        v.push_back({row - row0, col - col0});
        
        dfs(row-1, col, vis, grid, v, row0, col0);
        dfs(row+1, col, vis, grid, v, row0, col0);
        dfs(row, col-1, vis, grid, v, row0, col0);
        dfs(row, col+1, vis, grid, v, row0, col0);
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int,int>>> st;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                
                if(!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int,int>> v;
                    dfs(i, j, vis, grid, v, i, j);
                    st.insert(v);
                }
            }
        }
        return st.size();
        
        //T.C :- O(N * M) + O(N * M)*4  =>  O(N * M)
        //S.C :- O(N * M) + O(N * M)  =>    O(N * M)
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