class Solution{
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res); //用res变量存储结果
    }
    int helper(TreeNode* node, int& res) {
        if(!node) return 0;
        //计算左右子树的最大路径和
        int left = max(helper(node->left, res), 0); //如果选0,表示不加该子树
        int right = max(helper(node->right, res), 0); 
        //更新全局最大值
        res = max(res, left+right+node->val);
        return max(left, right) + node->val;
    }
};