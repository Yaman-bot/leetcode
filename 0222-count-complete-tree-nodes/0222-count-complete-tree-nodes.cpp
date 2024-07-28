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
    int findHeight(TreeNode *node,bool leftSubtree,bool rightSubtree){
        if(node==NULL)
            return 0;

        int cnt = 0;
        while(node){
            cnt++;
            if(leftSubtree)
                node=node->left;
            if(rightSubtree)
                node=node->right;
        }
        return cnt;
    }
    int countNodes(TreeNode *root)
    {
        if(root==NULL) return 0;

        int lh = findHeight(root, true,false);
        int rh = findHeight(root, false,true);

        if(lh==rh)
            return pow(2, lh)-1;

        return 1+countNodes(root->left) + countNodes(root->right);
    }
};