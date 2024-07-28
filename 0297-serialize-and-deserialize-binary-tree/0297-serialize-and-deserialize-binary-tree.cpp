/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         if(root==NULL)
             return "N";
             
        string left=serialize(root->left);
        string right=serialize(root->right);
        return  to_string(root->val) + "," + left + "," + right;
    }
    
    TreeNode* helper(queue<string> &q){
        if (q.size() == 0)
            return NULL;
        auto x = q.front();
        q.pop();
        if (x == "N")
            return NULL;
        TreeNode *root = new TreeNode(stoi(x));
        root->left = helper(q);
        root->right = helper(q);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream string_stream(data);
        queue<string> q;
        int i=0;
        while(string_stream.good()){
            string s;
            getline(string_stream, s, ','); //calling getline fuction
            q.push(s);
            i++;
        }
        
        TreeNode* root=helper(q);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));