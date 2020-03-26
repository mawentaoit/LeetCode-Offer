//只要求返回true或false，因此不需要记录路径
class Solution{
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) return false;
        if(root->left == nullptr && root->right == nullptr) return sum == root->val;
        int newSum = sum-root->val;
        return hasPathSum(root->left, newSum) || hasPathSum(root->right, newSum);
    }
};

//需要返回路径
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        pathSum( root, path, res, sum);
        return res;
    }
private:    
    void pathSum(TreeNode* root, vector<int>& path, vector<vector<int>>& res, int sum) {
        if(root == nullptr) return ;
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            if(sum == root->val) res.push_back(path);
        }
        pathSum(root->left, path, res, sum-root->val);
        pathSum(root->right, path, res, sum-root->val);
        path.pop_back();
    }
};
