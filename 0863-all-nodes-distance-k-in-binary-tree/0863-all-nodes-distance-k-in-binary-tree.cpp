/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_map)
    {
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent_map[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent_map[node->right] = node;
            }
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent_map;
        markParents(root, parent_map);

        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;
        q.push(target);
        visited[target] = true;
        int currLevel = 0;
        while (!q.empty())
        {
            int size = q.size();
            if(currLevel==k)
                break;
            currLevel++;
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                TreeNode *parent = parent_map[node];
                if (node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if(parent && !visited[parent]){
                    q.push(parent);
                    visited[parent] = true;
                }
            }
        }
        vector<int> result;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            result.push_back(node->val);
        }
        return result;
    }
};