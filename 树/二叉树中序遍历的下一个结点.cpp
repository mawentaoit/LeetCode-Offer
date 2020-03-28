/**
 * 二叉树中序遍历的下一个结点
 * 给定一个二叉树和其中一个结点，请找出中序遍历顺序下的下一个结点并返回
 * (1)有右子树的，那么下个结点就是右子树最左边的点
 * (2)没有右子树的，是父节点左孩子，那么父节点就是下一个结点
 * (3)没有右子树，是父节点右孩子找他的父结点的父节点的父节点。。。直到遍历到别的结点是其父节点的左孩子位置，
 * 返回该父节点。
 */
class Solution{
public:
    TreeNode* GetNext(TreeNode* p) {
        if(p == nullptr) return nullptr;
        if(p->right) {
            p = p->right;
            while(p->left != nullptr) {
                p = p->left;
            }
            return p;
        }
        else //没有右子树，下个节点就是父节点
        {
            while(p->next) {
                if(p->next->left == p) {
                    return p->next;
                }else p = p->next;
            }
            return nullptr;
        }
    }
};