 /**
  * 方法：递归法
  * 如果根节点的值大于p和q之间的较大值，说明p和q都在左子树中，那么此时我们就进入根节点的左子结点继续递归，如果根结点小于
  * p和q之间的较小值，说明p和q都在右子树中，那么此时我们就进入根节点的右子结点继续递归，如果都不是，则说明当前根结点就是最小公共父节点
  * 直接返回即可
  */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) //空结点是返回空
         return nullptr;
         //从根结点开始递归
         if(root->val > max(p->val, q->val)) //如果p,q在当前结点左子树，则对左子树遍历
          return lowestCommonAncestor(root->left, p, q);
        else if(root->val < min(p->val, q->val)) //遍历右子树
           return lowestCommonAncestor(root->right, p, q);
        else return root;    
    }
};
/**
 * 问题：普通二叉树的最低公共祖先
 * 方法：递归法
 * 这道题是普通二叉数，不是二叉搜索树，所以就不能利用其特有的性质，所以我们只能在
 * 二叉数中来搜索p和q,从左右子树中分别找到p,q,如果对于某个节点，左右分别有p,q，则说明该节点为最低公共祖先
 * 题目中没有明确说明p和q是否是树中的节点，如果不是，应该返回NULL
 */
class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || p == root || q == root) //如果p==root或者q==root，说明找到了p和q
        return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);//
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        else return left ? left : right; 
    }
};
