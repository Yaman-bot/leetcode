class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        vector<int> vis(arr.size(), 0);
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (arr[node] == 0)
                return true;
            int nbr1 = node + arr[node];
            int nbr2 = node - arr[node];
            if (nbr1 < arr.size() && vis[nbr1] == 0)
            {
                q.push(nbr1);
                vis[nbr1] = 1;
            }
            if (nbr2 >= 0 && vis[nbr2] == 0)
            {
                q.push(nbr2);
                vis[nbr2] = 1;
            }
        }
        return false;
    }
};