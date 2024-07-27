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
    bool checkTree(TreeNode* root) {
        if(root == NULL) return true;
        int leftans =0;
        int rightans = 0;
        if(root->left != NULL){
            leftans = root->left->val;
        }
        if(root->right != NULL){
            rightans = root->right->val;
        }
        int temp = leftans + rightans;
        if(root->val == temp) return true;
        else return false; 
    }
};