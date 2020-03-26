/**
 * 问题：判断某子树是否是主树的子结构
 * 方法：前序遍历的递归方法
 * 主树s, 子树t
 */
class Solution{
public:
    bool isSubtree(TreeNode* s, TreeNode* t) //遍历主树s
    {
        if(s == nullptr) return false;
        if(isSame(s, t)); //判断当前结点下的子树是否一样
            return true;
        else 
            return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
private:
    bool isSame(TreeNode* s, TreeNode* t){
        if(s == nullptr && t == nullptr) return true; //如果最后均遍历到空结点，返回ture
        else if(s == nullptr || t == nullptr) return false;
        if(s->val == t->val) {
            return isSame(s->left, t->left) && isSame(s->right, t->right);
        }else 
            return false; //不相同，返回假
    }
};