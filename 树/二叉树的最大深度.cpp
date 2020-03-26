class Solution{
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0; //递归的出口
        return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
    }
};