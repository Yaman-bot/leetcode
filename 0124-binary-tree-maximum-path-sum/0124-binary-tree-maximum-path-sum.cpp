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
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans=-1e9;
        helper(root,ans);
        return ans;
    }
    
    int helper(TreeNode* root,int &ans){
        if(root==NULL)
            return 0;
        
        int ls=max(0,helper(root->left,ans));
        int rs=max(0,helper(root->right,ans));
        
        ans=max(ans,root->val+ls+rs);
        return root->val+max(ls,rs);
    }
};