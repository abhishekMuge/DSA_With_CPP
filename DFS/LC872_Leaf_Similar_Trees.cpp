class Solution {
public:
    void dfs(TreeNode* root, vector<int>& res) {
        if(!root) return;
        if(!root->left && !root->right){
            res.push_back(root->val);
            return;
        }
        if(root->left) dfs(root->left, res);
        if(root->right) dfs(root->right, res);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1, l2;
        dfs(root1, l1);
        dfs(root2, l2);
        return l1 == l2;
    }
};