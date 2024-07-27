class Solution
{
public:
    TreeNode *markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_map,int start)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *res;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if(node->val==start)
                res = node;
            if (node->left)
            {
                q.push(node->left);
                parent_map[node->left] = node;
            }
            if (node->right)
            {
                q.push(node->right);
                parent_map[node->right] = node;
            }
        }
        return res;
    }
    int amountOfTime(TreeNode *root, int start)
    {
        unordered_map<TreeNode *, TreeNode *> parent_map;
        TreeNode* target=markParents(root, parent_map,start);

        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int time = 0;
        while (!q.empty())
        {
            int size = q.size();
            bool burnt = false;
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                TreeNode *parent = parent_map[node];
                if (node->left && !visited[node->left])
                {
                    burnt = true;
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right])
                {
                    burnt = true;
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if (parent && !visited[parent])
                {
                    burnt = true;
                    q.push(parent);
                    visited[parent] = true;
                }
            }
            if(burnt)
                time++;
        }
        return time;
    }
};