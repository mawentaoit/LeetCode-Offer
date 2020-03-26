class Solution{
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return false;
        return isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode* t1, TreeNode* t2) { //判断两个树是否为镜像关系
        //三个递归出口
        if(t1 == nullptr && t2 == nullptr) return true; //两结点同时为空时为true
        else if(t1 == nullptr || t2 == nullptr) return false;
        //当前结点值相等，且左结点的左子树和右节点的右子树对称，左结点的左子树和右结点的右子树对称
        return (t1->val == t2->val) && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};