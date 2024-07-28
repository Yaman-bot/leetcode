/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        map<int, int> inorder_map;

        for (int i = 0; i < inorder.size(); i++)
        {
            inorder_map[inorder[i]] = i;
        }

        TreeNode *root = constructTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inorder_map);
        return root;
    }

    TreeNode *constructTree(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inorder_map)
    {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(postorder[postEnd]);

        int inRoot = inorder_map[root->val];
        int numsLeft = inRoot - inStart;

        root->left = constructTree(postorder, postStart, postStart + numsLeft-1, inorder, inStart, inRoot - 1, inorder_map);
        root->right = constructTree(postorder, postStart + numsLeft, postEnd-1, inorder, inRoot + 1, inEnd, inorder_map);

        return root;
    }
};