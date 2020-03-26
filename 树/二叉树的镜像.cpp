//问题：变换二叉树为原来的镜像，联系问题：判断某二叉树是否为对称二叉树
class Solution{
public:
    void Mirror(TreeNode* pRoot) {
        if(pRoot == nullptr) return;
        if(pRoot->left == nullptr && pRoot->right == nullptr) return;
        swap(pRoot->left, pRoot->right); //如果当前结点有子节点就交换左右子结点
        if(pRoot->left) Mirror(pRoot->left); 
        if(pRoot->right) Mirror(pRoot->right);
    }
};